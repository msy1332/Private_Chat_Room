#pragma once // 防止头文件重复包含
#include <Windows.h> // 包含windowsAPI头文件
#include <iostream> // 包含标准输入输出头文件
#include <easyx.h> // 包含easyx图形库
#include <string> // 包含字符串(string)类的头文件
#include "../UI.h" // 包含UI接口类的头文件
#include "../../Tool/Tool.h" // 包含工具头文件

enum class ButtonType // 定义了一个强枚举类型，用来表示不同风格的按钮类型
{
	Have_border_fill,            // 带边框的填充按钮
	Borderless_fill,             // 不带边框的填充按钮
	Have_border_fill_rounded,    // 带边框的填充圆角按钮
	Borderless_fill_rounded,     // 不带边框的填充圆角按钮
	Picture                      // 图片按钮
};

enum class ButtonStatus // 定义了一个强枚举类型，用来表示当前按钮的交互状态
{
	Ordinary,	// 普通状态
	Suspended,	// 悬浮状态
	Press		// 按下状态
};

struct ButtonStatusColor // 定了一个结构体，用来表示按钮在这的三种交互状态下的颜色配置
{
	COLORREF Ordinary;	// 普通状态下的颜色
	COLORREF Suspended;	// 悬浮状态下的颜色
	COLORREF Press;		// 按下状态下的颜色
};

struct ButtonSizeLocation // 定义了一个结构体，用来表示按钮的大小，位置和圆角尺寸
{
	int x;				// 按钮的x坐标
	int y;				// 按钮的y坐标
	int width;			// 按钮的宽度
	int height;			// 按钮的高度
	int ellipsewidth;	// 按钮圆角的宽度
	int ellipseheight;	// 按钮圆角的高度
};

class Button : public UI // 定义了一个按钮的UI类，并继承这个UI的接口类
{
	public:
		Button(); // 默认构造函数，用来初始化按钮
		Button(Button& button); // 拷贝构造函数，用来初始化按钮
		~Button(); // 析构函数，用来释放按钮所用到的资源

		void SetButtonX(int x); // 重新设置按钮的x坐标
		void SetButtonY(int y); // 重新设置按钮的y坐标
		void SetText(std::wstring Text); // 重新设置按钮的标签
		void SetButtonType(ButtonType buttonType); // 重新设置按钮的风格，也就是按钮的类型
		void SetFillColor(ButtonStatusColor FillColor); // 重新按钮在三种的交互状态下的填充颜色
		void SetLineColor(ButtonStatusColor LineColor); // 重新按钮在三种的交互状态下的填充颜色
		void SetTextColor(ButtonStatusColor TextColor); // 重新按钮在三种的交互状态下的填充颜色
		void SetButtonStatusIMagePATH(const std::wstring* ButtonStatusIMagePATH); // 设置按钮在三种不同的交互状态下的图片的路径
		void SetButtonStatusIMage(const IMAGE* ButtonStatusIMage); // 设置按钮在三种不同的交互状态下的图片
		void SetButtonSizeLocation(ButtonSizeLocation buttonSizeLocation); // 重新设置按钮的大小，位置和圆角的宽度和高度

		void Draw() override; // 重写了接口类的绘制UI(Draw)的函数，用来绘制按钮
		UISignal Updata(ExMessage msg) override; // 重写了接口类的更新UI(Updata)函数，用来更新按钮的状态
		bool JudgmentMouseInside(int MouseX, int MouseY); // 判断鼠标是否在按钮里面
		void CalculationTextCenterLocation(); // 计算按钮标签的居中坐标
	private:
		Tool tool; // 实例化一个工具对象，并通过这个对象来调用这个透明贴图函数

		int TextCenterX; // 按钮标签居中的x
		int TextCenterY; // 按钮标签居中的y

		std::wstring ButtonText; // 定义了一个字符串，用来存储按钮的标签，也就是显示在按钮上面的文字
		ButtonType buttonType; // 定义了一个枚举变量，用来表示按钮的风格
		ButtonStatus buttonStatus; // 定义了一个枚举变量，用来表示当前按钮的交互状态
		
		std::string* ButtonStatusIMagePATH; // 定义了一个string字符串对象，用来存储按钮在三种不同的交互状态下的图片的路径
		IMAGE* ButtonStatusIMage; // 定义了一个IMAGE对象，用来存储按钮在三种不同的交互状态下的图片
		ButtonStatusColor FillColor; // 定了一个结构体变量，用来存储按钮在不同的交互状态下的填充颜色
		ButtonStatusColor LineColor; // 定了一个结构体变量，用来存储按钮在不同的交互状态下的线条颜色
		ButtonStatusColor TextColor; // 定了一个结构体变量，用来存储按钮在不同的交互状态下的文字颜色

		ButtonSizeLocation buttonSizeLocation; // 定义了一个结构体变量，用来存储按钮的大小，位置和圆角的宽度和高度
};