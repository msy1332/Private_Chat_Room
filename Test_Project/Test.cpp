#include <iostream> // 包含标准的输入输出头文件
#include <easyx.h> // 包含easyx图形库头文件
#include <vector> // 包含vector容器头文件
#include <map> // 包含映射头文件
using namespace std; // 使用std命名空间

namespace UIControl
{
	int CounterID = 0;
	
	enum class UISignal // 定义了一个强枚举类，用来表示控件触发信号类型
	{
		Click
	};
	
	enum class ButtonStatus // 定义了一个强枚举类型，用来表示当前按钮的交互状态
	{
		Ordinary,	// 普通状态
		Suspended,	// 悬浮状态
		Press		// 按下状态
	};
	
	struct ButtonSizeLocation
	{
		int x;
		int y;
		int width;
		int height;
	};
	
	class UI // UI接口类
	{
		public:
			virtual int GetID() = 0;
			virtual void Draw() = 0;
			virtual UISignal Updata(ExMessage msg) = 0;
	};
	
	class Button : public UI // 按钮类，并继承UI接口类
	{
		public:
			Button(); // 默认构造函数，用来初始化按钮控件
			Button(int x, int y, int width, int height); // 有参构造函数，用来初始化按钮控件
	
			int GetID() override; // 重写了UI接口类中的获取控件的ID函数，用来获取按钮控件的ID
			void Draw() override; // 重写UI接口类中的绘制函数，用来绘制按钮
			UISignal Updata(ExMessage msg) override; // 重写了UI接口类中的更新控件的状态函数，用来更新按钮的交互状态
			bool JudgmentMouseButtonInside(int MouseX,int MouseY); // 判断鼠标是否在按钮里面
		private:
			int ID;
			ButtonSizeLocation buttonSizeLocation;
			ButtonStatus buttonStatus;
	};
	
	Button::Button()
	{
		// 分配按钮控件的ID
		ID = CounterID++;
	
		// 初始化按钮的位置和大小
		buttonSizeLocation.x = 0;
		buttonSizeLocation.y = 0;
		buttonSizeLocation.width = 200;
		buttonSizeLocation.height = 50;
	
		// 初始化按钮的交互状态
		buttonStatus = ButtonStatus::Ordinary;
	}
	
	Button::Button(int x,int y,int width,int height)
	{
		// 分配按钮控件的ID
		ID = CounterID++;
	
		// 初始化按钮的位置和大小
		buttonSizeLocation.x = x;
		buttonSizeLocation.y = y;
		buttonSizeLocation.width = width;
		buttonSizeLocation.height = height;
	
		// 初始化按钮的交互状态
		buttonStatus = ButtonStatus::Ordinary;
	}
	
	int Button::GetID()
	{
		return ID;
	}
	
	void Button::Draw()
	{
		switch (buttonStatus)
		{
			case ButtonStatus::Ordinary:
				setfillcolor(RGB(225, 225, 225));
				setlinecolor(RGB(173, 173, 173));
				break;
			case ButtonStatus::Suspended:
				setfillcolor(RGB(229, 241, 251));
				setlinecolor(RGB(0, 120, 215));
				break;
			case ButtonStatus::Press:
				setfillcolor(RGB(204, 228, 247));
				setlinecolor(RGB(0, 84, 153));
				break;
		}
		fillrectangle(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height);
	}
	
	UISignal Button::Updata(ExMessage msg)
	{
		if (JudgmentMouseButtonInside(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
		{
			buttonStatus = ButtonStatus::Press;
			return UISignal::Click;
		}
		else if (JudgmentMouseButtonInside(msg.x, msg.y))
		{
			buttonStatus = ButtonStatus::Suspended;
		}
		else
		{
			buttonStatus = ButtonStatus::Ordinary;
		}
	}
	
	bool Button::JudgmentMouseButtonInside(int MouseX, int MouseY)
	{
		if (MouseX > buttonSizeLocation.x && MouseX < buttonSizeLocation.x + buttonSizeLocation.width && MouseY > buttonSizeLocation.y && MouseY < buttonSizeLocation.y + buttonSizeLocation.height)
			return 1;
		else
			return 0;
	}
}

int main()
{
	// 初始化绘图窗口
	initgraph(800, 600);
	setbkcolor(WHITE);
	cleardevice();

	// 初始化控件
	vector<UIControl::UI*> ui{ 
		new UIControl::Button(),
		new UIControl::Button(250, 0, 200, 50)
	};

	bool running = true;
	ExMessage msg;
	
	BeginBatchDraw();
	while (running)
	{
		while (peekmessage(&msg, EX_MOUSE))
		{
			for (int i = 0; i < ui.size(); i++)
			{
				//switch (ui[i]->Updata(msg))
				//{
				//	case UIControl::UISignal::Click:
				//		switch (ui[i]->GetID())
				//		{
				//			case 0:
				//				cout << "Button1 Click" << endl;
				//				break;
				//			case 1:
				//				cout << "Button2 Click" << endl;
				//				break;
				//		}
				//		break;
				//	default:
				//		break;
				//}
				if (ui[i]->Updata(msg) == UIControl::UISignal::Click)
				{
					switch (ui[i]->GetID())
					{
						case 0:
							cout << "Button1 Click" << endl;
							break;
						case 1:
							cout << "Button2 Click" << endl;
							break;
					}
				}
			}
		}
		cleardevice();
		for (int i = 0; i < ui.size(); i++)
		{
			ui[i]->Draw();
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	return 0;
}