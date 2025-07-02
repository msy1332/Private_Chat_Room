#include <iostream> // 包含标准输入输出头文件
#include <windows.h> // 包含windows系统的API头文件
#include <vector> // 包含vector容器的头文件
#include "../UI/UI.h" // 包含UI接口类的头文件
#include "../UI/Button/Button.h" // 包含按钮的头文件
using namespace std;
int main()
{
	// 初始化窗口
	initgraph(800, 600, EX_SHOWCONSOLE); // 创建窗口
	setbkcolor(RGB(240, 240, 240)); // 设置背景颜色
	cleardevice(); // 清除绘图窗口，并用背景颜色填充整个窗口
	setbkmode(TRANSPARENT); // 设置背景模式为透明模式，这样绘制出的文字的背景就是透明的

	// 初始化UI
	Button button;
	Button button1;
	vector<UI*> ui = { &button,&button1 };

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


	bool Running = true; // 定义了一个bool变量，用来标记程序的运行状态
	ExMessage msg; // 定义一个消息结构体，用来存储获取到消息

	BeginBatchDraw(); // 开启双缓冲绘图
	while (Running)
	{
		while (peekmessage(&msg, EX_MOUSE)) // 获取消息
		{
			button.Updata(msg); // 更新按钮的交互状态
			if(button1.Updata(msg) == UISignal::Click) // 更新按钮的交互状态
			{
				Running = false;
			}
		}

		cleardevice(); // 清除绘图窗口，并用背景颜色填充整个窗口
		//button.Draw(); // 绘制按钮
		//button1.Draw(); // 绘制按钮
		for (auto it : ui)
			it->Draw();
		FlushBatchDraw(); // 刷新绘图缓冲区
	}
	EndBatchDraw(); // 结束双缓冲绘图
	return 0;
}