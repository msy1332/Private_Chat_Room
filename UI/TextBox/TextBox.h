#pragma once // 防止头文件重复包含
#include <iostream> // 包含标准输入输出头文件
#include <easyx.h> // 包含easyx图形库
#include <string> // 包含字符串(string)头文件
#include "../UI.h" // 包含UI接口类的头文件

enum class TextBoxType // 定义了一个强枚举类，用来表示不同风格的文本输入框类型
{
	Have_border_fill,            // 带边框的填充文本输入框
	Borderless_fill,             // 不带边框的填充文本输入框
	Have_border_fill_rounded,    // 带边框的填充圆角文本输入框
	Borderless_fill_rounded,     // 不带边框的填充圆角文本输入框
};

enum class TextBoxStatus // 定义一个强枚举类，用来表示当前文本输入框的交互状态
{
	Ordinary,	// 普通状态
	Suspended,	// 悬浮状态
	Input		// 输入状态
};

enum class TextBoxMode // 定义了一个强枚举类，用来表示当前文本输入框的模式
{
	Single_line, // 单行模式
	Multiple_lines // 多行模式
};

struct TextBoxStatusColor // 定了一个结构体，用来表示文本输入框在这的三种交互状态下的颜色配置
{
	COLORREF Ordinary;	// 普通状态下的颜色
	COLORREF Suspended;	// 悬浮状态下的颜色
	COLORREF Press;		// 按下状态下的颜色
};

struct TextStyle // 定义一个结构体，用来存储文本输入框的文本大小
{
	int TextWidth;  // 文本输入框的文本的宽度
	int TextHeigth; // 文本输入框的文本的高度
};

struct TextBoxSizeLocation // 定义一个结构体，用来存储文本输入框的大小，位置和圆角的尺寸
{
	int x; // 文本输入框的x坐标
	int y; // 文本输入框的y坐标
	int width; // 文本输入框的宽度
	int ellipsewidth;	// 文本输入框圆角的宽度
	int ellipseheight;	// 文本输入框圆角的高度
};

class TextBox : public UI // 定义了一个文本输入框的UI类，并继承这个UI的接口类
{
	public:
	private:
	protected:
};