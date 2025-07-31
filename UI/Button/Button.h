#pragma once // 防止头文件重复包含
#include <iostream> // 包含标准输入输出头文件
#include <easyx.h> // 包含easyx图形库头文件
#include <string> // 包含string字符串类头文件
#include "../UI.h" // 包含UI接口类头文件
#include "../../Tool/Tool.h" // 包含Tool工具头文件

namespace UIControl // 定义了一个UI控件命名空间，为了防止命名冲突
{
	enum class ButtonType // 定义了一个强枚举类，用来表示不同风格的按钮的类型
	{
		With_borders_Fill_Button,				// 带边框的填充按钮
		Without_borders_Fill_Button,			// 不带边框的填充按钮
		With_borders_Fill_Rounded_Button,		// 带边框的填充圆角按钮
		Without_borders_Fill_Rounded_Button,	// 不带边框的填充圆角按钮
		Picture_Button							// 图片按钮
	};

	enum class ButtonStatus // 定义了一个强枚举类，用来表示按钮的三种不同的交互状态
	{
		Ordinary,	// 普通状态
		Suspended,	// 悬浮状态
		Press		// 按下状态
	};

	struct ButtonStatusColor // 定义了一个结构体，用来存储按钮的三种不同交互状态下的不同的填充，线条和文字颜色，文字颜色也就是按钮标签颜色
	{ 
		COLORREF Ordinary;  // 普通交互状态的颜色
		COLORREF Suspended; // 悬浮交互状态的颜色
		COLORREF Press;		// 按下交互状态的颜色
	};

	struct ButtonSizeLocation // 定义了一个结构体，用来存储按钮的大小和位置
	{
		int x;				// 按钮的x坐标
		int y;				// 按钮的y坐标
		int width;			// 按钮的宽度
		int height;			// 按钮的高度
		int ellipseWidth;   // 圆角的宽度
		int ellipseHeight;  // 圆角的高度
	};

	struct ButtonTagStyle // 定义了一个结构体，用来存储按钮标签的样式，也就是这个按钮标签文本大小和字体
	{
		int width;	// 按钮标签文本的宽度
		int height;	// 按钮标签文本的高度
		std::wstring Font; // 按钮标签文本字体
	};

	class Button : public UI // 定义了一个Button(按钮)类,并继承UI接口类
	{
		public:
			Button(); // 默认构造函数，用来初始化按钮控件
			Button(const Button& button); // 拷贝构造函数，用来初始化按钮控件
			~Button(); // 析构函数，释放按钮所有到的资源

			void SetButtonType(ButtonType buttonType); // 重新设置按钮的风格
			void SetButtonTag(std::wstring ButtonTag); // 重新设置按钮的标签
			void SetButtonTagStyle(ButtonTagStyle buttonTagStyle); // 重新设置按钮标签样式，也就是这个按钮标签文本大小和字体
			void SetButtonStatusFill(ButtonStatusColor FillColor); // 重新设置按钮的三种的交互状态下的不同填充颜色
			void SetButtonStatusLine(ButtonStatusColor LineColor); // 重新设置按钮的三种的交互状态下的不同线条颜色
			void SetButtonStatusText(ButtonStatusColor TextColor); // 重新设置按钮的三种的交互状态下的不同文字颜色，也就是按钮标签的颜色
			void SetButtonLocation(int x,int y); // 重新设置按钮位置
			void SetButtonSize(int width, int height); // 重新设置按钮的大小
			void SetButtonSizeLocation(ButtonSizeLocation buttonSizeLocation); // 重新设置按钮的大小和位置
			void SetButtonImage(IMAGE* img); // 设置图片按钮的三种交互状态下的不同的图片
			void SetButtonImagePath(std::wstring* path); // 设置图片按钮的三种交互状态下的不同图片的路径

			inline int GetID() override; // 重写接口类中的获取控件ID函数，用来获取按钮控件的ID
			void Draw() override; // 重写接口类中的绘制控件函数，用来绘制按钮控件
			UIControl::ControlSignal Update(const ExMessage& msg) override; // 重写接口类中的更新控件函数，用来更新按钮控件的交互状态
			bool JudgmentMouseButtonInside(int MouseX, int MouseY); // 判断鼠标是否在按钮里面
			void CalculationButtonTagCenterCoordinate(); // 计算按钮标签居中坐标
		private:
			Tool tool; // 定义工具对象，用工具对象来调用透明贴图函数，因为，有些按钮图片是透明的

			bool FlagID = false; // 定义例如一个布尔(bool)变量，用来标记按钮控件是否分配了唯一ID
			int ID; // 定义了一个整形变量，用来存储控件唯一ID

			int ButtonTagCenterX; // 定义了一个整形变量，用来存储按钮标签居中x坐标
			int ButtonTagCenterY; // 定义了一个整形变量，用来存储按钮标签居中y坐标
			std::wstring ButtonTag; // 定义了一个字符串对象，用来存储按钮标签
			ButtonTagStyle buttonTagStyle; // 定义了一个结构体变量，用来存储按钮标签的样式，也就是这个按钮标签文本大小和字体

			ButtonType buttonType; // 定义了一个强枚举变量，用来表示按钮的风格
			ButtonStatus buttonStatus; // 定义了一个强枚举变量，用来表示当前按钮的交互状态

			// 定义了三个结构体变量，他们分别用来存储按钮在这三种不同的交互状态下的不同的填充，线条和文字颜色，文字颜色也就是按钮标签的颜色
			ButtonStatusColor LineColor;
			ButtonStatusColor FillColor;
			ButtonStatusColor TextColor;

			IMAGE* ButtonStatusImage; // 定义了一个图片指针，用来存储按钮的三种不同交互状态下的不同的按钮图片

			ButtonSizeLocation buttonSizeLocation; // 定义了一个结构体变量，用来存储按钮的大小和位置
	};
}