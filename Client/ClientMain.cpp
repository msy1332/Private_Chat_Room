#include <iostream> // 包含标准输入输出头文件
#include <windows.h> // 包含windows系统的API头文件
#include <vector> // 包含vector容器的头文件
#include "../UI/UI.h" // 包含UI接口类的头文件
#include "../UI/Button/Button.h" // 包含按钮的头文件
#include "../UI/TextBox/TextBox.h" // 包含文本输入框头文件
#include "../Tool/Tool.h" // 包含工具头文件
using namespace std; // 使用std命名空间
using namespace UIControl; // 使用UIControl命名空间
int main()
{
	// 初始化窗口
	initgraph(800, 600, EX_SHOWCONSOLE); // 创建窗口
	setbkcolor(RGB(240, 240, 240)); // 设置背景颜色
	cleardevice(); // 清除绘图窗口，并用背景颜色填充整个窗口
	setbkmode(TRANSPARENT); // 设置背景模式为透明模式，这样绘制出的文字的背景就是透明的

	/*
		// 初始化UI
		Button button;
		Button button1;
		TextBox textbox1;
		vector<UI*> ui = { &button,&button1, &textbox1};

		ButtonSizeLocation buttonSizeLocation;
		buttonSizeLocation.x = 778;
		buttonSizeLocation.y = 2;
		buttonSizeLocation.width = 20;
		buttonSizeLocation.height = 20;
		button1.SetButtonSizeLocation(buttonSizeLocation);

		button1.SetButtonType(ButtonType::Borderless_fill);
		button1.SetText(L"×");

		ButtonStatusColor Fill;
		Fill.Ordinary = RGB(240, 240, 240);
		Fill.Suspended = RGB(232, 17, 35);
		Fill.Press = RGB(241, 112, 122);
		button1.SetFillColor(Fill);

		ButtonStatusColor Text;
		Text.Ordinary = RGB(5, 7, 8);
		Text.Suspended = RGB(255, 255, 255);
		Text.Press = RGB(255, 255, 255);
		button1.SetTextColor(Text);
	*/

	// 初始化UI
	Button button1;

	Button button2;
	button2.SetButtonType(ButtonType::Without_borders_Fill_Button);
	button2.SetButtonLocation(220, 0);

	Button button3;
	button3.SetButtonType(ButtonType::With_borders_Fill_Rounded_Button);
	// 设置按钮的大小和位置
	ButtonSizeLocation buttonSizeLocation1;
	buttonSizeLocation1.x = 0;
	buttonSizeLocation1.y = 70;
	buttonSizeLocation1.width = 200;
	buttonSizeLocation1.height = 50;
	buttonSizeLocation1.ellipseWidth = 15;
	buttonSizeLocation1.ellipseHeight = 15;
	button3.SetButtonSizeLocation(buttonSizeLocation1);

	Button button4;
	button4.SetButtonType(ButtonType::Without_borders_Fill_Rounded_Button);
	// 设置按钮的大小和位置
	ButtonSizeLocation buttonSizeLocation2;
	buttonSizeLocation2.x = 220;
	buttonSizeLocation2.y = 70;
	buttonSizeLocation2.width = 200;
	buttonSizeLocation2.height = 50;
	buttonSizeLocation2.ellipseWidth = 15;
	buttonSizeLocation2.ellipseHeight = 15;
	button4.SetButtonSizeLocation(buttonSizeLocation2);

	Button button5;
	button5.SetButtonType(ButtonType::Picture_Button);
	button5.SetButtonLocation(0, 140);
	wstring ButtonStatusImagePath[3];
	ButtonStatusImagePath[0] = L"E:\\C++\\VS_Project\\Private_Chat_Room\\Private_Chat_Room\\Res\\Image\\Button1.png";
	ButtonStatusImagePath[1] = L"E:\\C++\\VS_Project\\Private_Chat_Room\\Private_Chat_Room\\Res\\Image\\Button2.png";
	ButtonStatusImagePath[2] = L"E:\\C++\\VS_Project\\Private_Chat_Room\\Private_Chat_Room\\Res\\Image\\Button3.png";
	button5.SetButtonImagePath(ButtonStatusImagePath);

	vector<UI*> ui{ &button1,&button2,&button3,&button4,&button5 };

	bool Running = true; // 定义了一个bool变量，用来标记程序的运行状态
	ExMessage msg; // 定义一个消息结构体，用来存储获取到消息

	BeginBatchDraw(); // 开启双缓冲绘图
	while (Running)
	{
		while (peekmessage(&msg, EX_MOUSE)) // 获取消息
		{
			//button.Updata(msg); // 更新按钮的交互状态
			//if(button1.Updata(msg) == UISignal::Click) // 更新按钮的交互状态
			//{
			//	Running = false;
			//}
			for (auto it : ui)
			{
				if (it->Updata(msg) == ControlSignal::Click)
				{
					switch (it->GetID())
					{
					case 0:
						cout << "Button0 Click" << endl;
						break;
					case 1:
						cout << "Button1 Click" << endl;
						break;
					case 2:
						cout << "Button2 Click" << endl;
						break;
					case 3:
						cout << "Button3 Click" << endl;
						break;
					case 4:
						cout << "Button4 Click" << endl;
						break;
					case 5:
						cout << "Button5 Click" << endl;
						break;
					}
				}
			}
			//button1.Updata(msg);
			//button2.Updata(msg);
			/*button3.Updata(msg);*/
		}

		cleardevice(); // 清除绘图窗口，并用背景颜色填充整个窗口
		////button.Draw(); // 绘制按钮
		////button1.Draw(); // 绘制按钮
		for (auto it : ui)
			it->Draw();
		//button1.Draw();
		//button2.Draw();
		/*button3.Draw();*/
		FlushBatchDraw(); // 刷新绘图缓冲区
	}
	EndBatchDraw(); // 结束双缓冲绘图
	return 0;
}
