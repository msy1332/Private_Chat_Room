#include <iostream> // ������׼���������ͷ�ļ�
#include <easyx.h> // ����easyxͼ�ο�ͷ�ļ�
#include <vector> // ����vector����ͷ�ļ�
#include <map> // ����ӳ��ͷ�ļ�
using namespace std; // ʹ��std�����ռ�

namespace UIControl
{
	int CounterID = 0;
	
	enum class UISignal // ������һ��ǿö���࣬������ʾ�ؼ������ź�����
	{
		Click
	};
	
	enum class ButtonStatus // ������һ��ǿö�����ͣ�������ʾ��ǰ��ť�Ľ���״̬
	{
		Ordinary,	// ��ͨ״̬
		Suspended,	// ����״̬
		Press		// ����״̬
	};
	
	struct ButtonSizeLocation
	{
		int x;
		int y;
		int width;
		int height;
	};
	
	class UI // UI�ӿ���
	{
		public:
			virtual int GetID() = 0;
			virtual void Draw() = 0;
			virtual UISignal Updata(ExMessage msg) = 0;
	};
	
	class Button : public UI // ��ť�࣬���̳�UI�ӿ���
	{
		public:
			Button(); // Ĭ�Ϲ��캯����������ʼ����ť�ؼ�
			Button(int x, int y, int width, int height); // �вι��캯����������ʼ����ť�ؼ�
	
			int GetID() override; // ��д��UI�ӿ����еĻ�ȡ�ؼ���ID������������ȡ��ť�ؼ���ID
			void Draw() override; // ��дUI�ӿ����еĻ��ƺ������������ư�ť
			UISignal Updata(ExMessage msg) override; // ��д��UI�ӿ����еĸ��¿ؼ���״̬�������������°�ť�Ľ���״̬
			bool JudgmentMouseButtonInside(int MouseX,int MouseY); // �ж�����Ƿ��ڰ�ť����
		private:
			int ID;
			ButtonSizeLocation buttonSizeLocation;
			ButtonStatus buttonStatus;
	};
	
	Button::Button()
	{
		// ���䰴ť�ؼ���ID
		ID = CounterID++;
	
		// ��ʼ����ť��λ�úʹ�С
		buttonSizeLocation.x = 0;
		buttonSizeLocation.y = 0;
		buttonSizeLocation.width = 200;
		buttonSizeLocation.height = 50;
	
		// ��ʼ����ť�Ľ���״̬
		buttonStatus = ButtonStatus::Ordinary;
	}
	
	Button::Button(int x,int y,int width,int height)
	{
		// ���䰴ť�ؼ���ID
		ID = CounterID++;
	
		// ��ʼ����ť��λ�úʹ�С
		buttonSizeLocation.x = x;
		buttonSizeLocation.y = y;
		buttonSizeLocation.width = width;
		buttonSizeLocation.height = height;
	
		// ��ʼ����ť�Ľ���״̬
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
	// ��ʼ����ͼ����
	initgraph(800, 600);
	setbkcolor(WHITE);
	cleardevice();

	// ��ʼ���ؼ�
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