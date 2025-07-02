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
	button1.SetButtonX(210);

	bool Running = true; // 定义了一个bool变量，用来标记程序的运行状态
	ExMessage msg; // 定义一个消息结构体，用来存储获取到消息

	BeginBatchDraw(); // 开启双缓冲绘图
	while (Running)
	{
		while (peekmessage(&msg, EX_MOUSE)) // 获取消息
		{
			button.Updata(msg); // 更新按钮的交互状态
			button1.Updata(msg); // 更新按钮的交互状态
		}

		cleardevice(); // 清除绘图窗口，并用背景颜色填充整个窗口
		button.Draw(); // 绘制按钮
		button1.Draw(); // 绘制按钮
		FlushBatchDraw(); // 刷新绘图缓冲区
	}
	EndBatchDraw(); // 结束双缓冲绘图
	return 0;
}