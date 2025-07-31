#pragma once // 防止头文件重复包含
#include <iostream> // 包含标准输入输出头文件
#include <easyx.h> // 包含easyx图形库
#include <string> // 包含字符串(string)头文件
#include <windows.h> // 包含windows API头文件
#include "../UI.h" // 包含UI接口类头文件
using namespace std; // 使用std命名空间

namespace UIControl // 定义了一个UI控件命名空间，为了防止命名冲突
{
	enum class TextBoxType // 定义了一个强枚举类，用来表示不同风格的文本输入框类型
	{
		With_borders_Fill_TextBox,				// 带边框的文本输入框
		Without_borders_Fill_TextBox,			// 不带边框的文本输入框
		With_borders_Fill_Rounded_TextBox,		// 带边框的圆角文本输入框
		Without_borders_Fill_Rounded_TextBox,	// 不带边框的圆角文本输入框
	};

	enum class TextBoxStatus // 定义了一个强枚举类，用来表示文本输入框的三种不同的交互状态
	{
		Ordinary,	// 普通状态
		Suspended,	// 悬浮状态
		Input		// 输入状态
	};

	enum class TextBoxMode // 定义了一个强枚举类，用来表示文本输入框的模式
	{
		Single_line,	// 单行模式
		Multiple_lines	// 多行模式
	};

	struct TextBoxTexiStyle // 定义了一个结构体，用来存储文本输入框文本的样式
	{
		int width; // 文本的宽度
		int height;// 文本的高度
		std::wstring Font; // 文本的字体的样式
		bool AlignMode; // 文本的对齐模式
	};

	struct TextBoxStatusColor // 定义了一个结构体变量，用来存储文本输入框的三种不同的交互状态下的填充，线条和文本颜色
	{ 
		COLORREF Ordinary;	// 普通交互状态下的颜色
		COLORREF Suspended;	// 悬浮交互状态下的颜色
		COLORREF Input;		// 输入交互状态下的颜色
	};

	struct TextSizeLocation // 定义了一个结构体，用来存储文本输入框大小和位置
	{
		int x;		// 文本输入框的x坐标
		int y;		// 文本输入框的y坐标
		int width;	// 文本输入框的宽度
		int line;   // 文本输入框的行
	};

	class TextBox : public UI // 定义了一个文本输入框类，并继承UI接口类
	{
		public:
			TextBox();
			TextBox(const TextBox& textBox);
			~TextBox();

			int GetID() override; // 重写了接口类中的获取控件ID函数，用来获取文本输入框控件ID
			void Draw() override; // 重写了接口类的绘制控件函数，用来绘制文本输入框控件函数
			UIControl::ControlSignal Update(const ExMessage& msg) override; // 重写了接口类中的更新控件状态函数，用来更新文本输入框控件状态函数
		private:
			int ID; // 定义整形变量，用来存储文本输入框控件ID

			TextBoxType textBoxType; // 定义了一个强枚举变量，用来表示文本输入框风格
			TextBoxStatus textBoxStatus; // 定义了一个强枚举变量，用来表示当前文本输入框交互状态
			TextBoxMode textBoxMode; // 定义了一个强枚举变量，用来表示文本输入框模式

			TextBoxTexiStyle textBoxTexiStyle; // 定义了一个结构体变量，用来存储文本输入框文本的样式
			
			// 定义了三个结构体变量，分别是用来存储文本输入框在这三种不同的交互状态下的填充，线条和文本颜色
			TextBoxStatusColor FillColor;
			TextBoxStatusColor LineColor;
			TextBoxStatusColor TextColor;

			TextSizeLocation textSizeLocation; //定义了一个结构体变量，用来存储文本输入框大小和位置
	};
}
