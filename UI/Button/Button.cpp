#include "Button.h" // 包含按钮模块的定义头文件
using namespace UIControl; // 使用UIControl命名空间

Button::Button()
{
	// 给这个按钮控件分配一个唯一ID
	if (FlagID == false) // 判断按钮控件是否分配了唯一ID,如果没分配的会，则会分配一个唯一ID,否则不分配
	{
		ID = CounterID++;
		FlagID = true;
	}

	// 初始化按钮的风格
	buttonType = ButtonType::With_borders_Fill_Button;

	// 初始化按钮交互状态
	buttonStatus = ButtonStatus::Ordinary;

	// 初始化按钮在这三种不同的交互状态下的填充，线条和按钮标签的颜色
	FillColor.Ordinary = RGB(225, 225, 225);
	FillColor.Suspended = RGB(229, 241, 251);
	FillColor.Press = RGB(204, 228, 247);

	LineColor.Ordinary = RGB(173, 173, 173);
	LineColor.Suspended = RGB(0, 120, 215);
	LineColor.Press = RGB(0, 84, 153);

	TextColor.Ordinary = RGB(0, 0, 0);
	TextColor.Suspended = RGB(0, 0, 0);
	TextColor.Press = RGB(0, 0, 0);

	// 初始化按钮大小和位置
	buttonSizeLocation.x = 0;
	buttonSizeLocation.y = 0;
	buttonSizeLocation.width = 200; 
	buttonSizeLocation.height = 50;

	// 初始化按钮标签
	buttonTagStyle.height = 20;
	buttonTagStyle.width = 0;
	buttonTagStyle.Font = L"宋体";
	ButtonTag = L"button" + std::to_wstring(ID);
	CalculationButtonTagCenterCoordinate(); // 计算按钮标签居中坐标
}

Button::Button(const Button& button)
{
	// 给这个按钮控件分配一个唯一ID
	if (FlagID == false) // 判断按钮控件是否分配了唯一ID,如果没分配的会，则会分配一个唯一ID,否则不分配
	{
		ID = CounterID++;
		FlagID = true;
	}

	// 拷贝按钮的风格
	buttonType = button.buttonType;

	// 初始化按钮交互状态
	buttonStatus = ButtonStatus::Ordinary;

	// 拷贝按钮在这三种不同的交互状态下的填充，线条和按钮标签的颜色
	FillColor = button.FillColor;
	LineColor = button.LineColor;
	TextColor = button.TextColor;

	// 拷贝按钮大小和位置
	buttonSizeLocation = button.buttonSizeLocation;

	// 初始化按钮标签
	ButtonTag = L"button" + ID;
}

Button::~Button()
{
	delete[] ButtonStatusImage; // 释放按钮所用到的图片资源
}

void Button::SetButtonType(ButtonType buttonType) // 重新设置按钮的风格
{
	this->buttonType = buttonType;
}

void Button::SetButtonTag(std::wstring ButtonTag) // 重新设置按钮的标签
{
	this->ButtonTag = ButtonTag;
}

void Button::SetButtonTagStyle(ButtonTagStyle buttonTagStyle) // 重新设置按钮标签样式，也就是这个按钮标签文本大小和字体
{
	this->buttonTagStyle = buttonTagStyle;
	CalculationButtonTagCenterCoordinate(); // 重新计算按钮标签居中坐标
}

void Button::SetButtonStatusFill(ButtonStatusColor FillColor) // 重新设置按钮的三种的交互状态下的不同填充颜色
{
	this->FillColor = FillColor;
}

void Button::SetButtonStatusLine(ButtonStatusColor LineColor) // 重新设置按钮的三种的交互状态下的不同线条颜色
{
	this->LineColor = LineColor;
}

void Button::SetButtonStatusText(ButtonStatusColor TextColor) // 重新设置按钮的三种的交互状态下的不同文字颜色，也就是按钮标签的颜色
{
	this->TextColor = TextColor;
}

void Button::SetButtonLocation(int x, int y) // 重新设置按钮位置
{
	this->buttonSizeLocation.x = x;
	this->buttonSizeLocation.y = y;
	CalculationButtonTagCenterCoordinate(); // 重新计算按钮标签居中坐标
}

void Button::SetButtonSize(int width, int height) // 重新设置按钮的大小
{
	this->buttonSizeLocation.width = width;
	this->buttonSizeLocation.height = height;
	CalculationButtonTagCenterCoordinate(); // 重新计算按钮标签居中坐标
}

void Button::SetButtonSizeLocation(ButtonSizeLocation buttonSizeLocation) // 重新设置按钮的大小和位置
{
	this->buttonSizeLocation = buttonSizeLocation;
	CalculationButtonTagCenterCoordinate(); // 重新计算按钮标签居中坐标
}

void Button::SetButtonImage(IMAGE* img) // 设置图片按钮的三种交互状态下的不同的按钮图片
{
	ButtonStatusImage = new IMAGE[3]; // 分配空间

	for (int i = 0; i < 3; i++) // 逐个将按钮图片拷贝过来
		ButtonStatusImage[i] = img[i];

	// 重新初始化按钮宽度和高度
	buttonSizeLocation.width = ButtonStatusImage[0].getwidth();
	buttonSizeLocation.height = ButtonStatusImage[0].getheight();
}

void Button::SetButtonImagePath(std::wstring* path) // 设置图片按钮的三种交互状态下的不同按钮图片的路径
{
	ButtonStatusImage = new IMAGE[3]; // 分配空间

	for (int i = 0; i < 3; i++) // 逐个将按钮图片加载过来
		loadimage(&ButtonStatusImage[i], path[i].c_str());

	// 重新初始化按钮宽度和高度
	buttonSizeLocation.width = ButtonStatusImage[0].getwidth();
	buttonSizeLocation.height = ButtonStatusImage[0].getheight();
}

int Button::GetID()
{
	return ID;
}

void Button::Draw()
{
	switch (buttonType)
	{
		case ButtonType::With_borders_Fill_Button:
			switch (buttonStatus)
			{
				case ButtonStatus::Ordinary:
					setfillcolor(FillColor.Ordinary);
					setlinecolor(LineColor.Ordinary);
					settextcolor(TextColor.Ordinary);
					break;
				case ButtonStatus::Suspended:
					setfillcolor(FillColor.Suspended);
					setlinecolor(LineColor.Suspended);
					settextcolor(TextColor.Suspended);
					break;
				case ButtonStatus::Press:
					setfillcolor(FillColor.Press);
					setlinecolor(LineColor.Press);
					settextcolor(TextColor.Press);
					break;
			}
			fillrectangle(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height);

			// 设置按钮标签样式，也就是标签文本的大小和字体
			settextstyle(buttonTagStyle.height, buttonTagStyle.width, buttonTagStyle.Font.c_str());
			outtextxy(ButtonTagCenterX, ButtonTagCenterY, ButtonTag.c_str());
			break;
		case ButtonType::Without_borders_Fill_Button:
			switch (buttonStatus)
			{
				case ButtonStatus::Ordinary:
					setfillcolor(FillColor.Ordinary);
					setlinecolor(FillColor.Ordinary);
					settextcolor(TextColor.Ordinary);
					break;
				case ButtonStatus::Suspended:
					setfillcolor(FillColor.Suspended);
					setlinecolor(FillColor.Suspended);
					settextcolor(TextColor.Suspended);
					break;
				case ButtonStatus::Press:
					setfillcolor(FillColor.Press);
					setlinecolor(FillColor.Press);
					settextcolor(TextColor.Press);
					break;
			}
			fillrectangle(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height);

			// 设置按钮标签样式，也就是标签文本的大小和字体
			settextstyle(buttonTagStyle.height, buttonTagStyle.width, buttonTagStyle.Font.c_str());
			outtextxy(ButtonTagCenterX, ButtonTagCenterY, ButtonTag.c_str());
			break;
		case ButtonType::With_borders_Fill_Rounded_Button:
			switch (buttonStatus)
			{
				case ButtonStatus::Ordinary:
					setfillcolor(FillColor.Ordinary);
					setlinecolor(LineColor.Ordinary);
					settextcolor(TextColor.Ordinary);
					break;
				case ButtonStatus::Suspended:
					setfillcolor(FillColor.Suspended);
					setlinecolor(LineColor.Suspended);
					settextcolor(TextColor.Suspended);
					break;
				case ButtonStatus::Press:
					setfillcolor(FillColor.Press);
					setlinecolor(LineColor.Press);
					settextcolor(TextColor.Press);
					break;
			}
			fillroundrect(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height, buttonSizeLocation.ellipseWidth, buttonSizeLocation.ellipseHeight);

			/*std::cout << "buttonSizeLocation_X: " << buttonSizeLocation.x << std::endl;
			std::cout << "buttonSizeLocation_Y: " << buttonSizeLocation.y << std::endl;
			std::cout << "buttonSizeLocation_Witdh: " << buttonSizeLocation.width << std::endl;
			std::cout << "buttonSizeLocation_Height: " << buttonSizeLocation.height << std::endl;
			std::cout << "buttonSizeLocation_ellipseWidth: " << buttonSizeLocation.ellipseWidth << std::endl;
			std::cout << "buttonSizeLocation_ellipseHeight: " << buttonSizeLocation.ellipseHeight << std::endl;*/

			// 设置按钮标签样式，也就是标签文本的大小和字体
			settextstyle(buttonTagStyle.height, buttonTagStyle.width, buttonTagStyle.Font.c_str());
			outtextxy(ButtonTagCenterX, ButtonTagCenterY, ButtonTag.c_str());
			break;
		case ButtonType::Without_borders_Fill_Rounded_Button:
			switch (buttonStatus)
			{
				case ButtonStatus::Ordinary:
					setfillcolor(FillColor.Ordinary);
					setlinecolor(FillColor.Ordinary);
					settextcolor(TextColor.Ordinary);
					break;
				case ButtonStatus::Suspended:
					setfillcolor(FillColor.Suspended);
					setlinecolor(FillColor.Suspended);
					settextcolor(TextColor.Suspended);
					break;
				case ButtonStatus::Press:
					setfillcolor(FillColor.Press);
					setlinecolor(FillColor.Press);
					settextcolor(TextColor.Press);
					break;
			}
			fillroundrect(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height, buttonSizeLocation.ellipseWidth, buttonSizeLocation.ellipseHeight);

			// 设置按钮标签样式，也就是标签文本的大小和字体
			settextstyle(buttonTagStyle.height, buttonTagStyle.width, buttonTagStyle.Font.c_str());
			outtextxy(ButtonTagCenterX, ButtonTagCenterY, ButtonTag.c_str());
			break;
		case ButtonType::Picture_Button:
			switch (buttonStatus)
			{
				case ButtonStatus::Ordinary:
					tool.Transparent_texture(buttonSizeLocation.x, buttonSizeLocation.y, &ButtonStatusImage[0]);
					break;
				case ButtonStatus::Suspended:
					tool.Transparent_texture(buttonSizeLocation.x, buttonSizeLocation.y, &ButtonStatusImage[1]);
					break;
				case ButtonStatus::Press:
					tool.Transparent_texture(buttonSizeLocation.x, buttonSizeLocation.y, &ButtonStatusImage[2]);
					break;
			}
			break;
	}
}

ControlSignal Button::Updata(const ExMessage& msg)
{
	if (JudgmentMouseButtonInside(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		buttonStatus = ButtonStatus::Press;
		return ControlSignal::Click;
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

void Button::CalculationButtonTagCenterCoordinate()
{
	// 设置按钮标签样式，也就是标签文本的大小和字体
	settextstyle(buttonTagStyle.height, buttonTagStyle.width, buttonTagStyle.Font.c_str());

	// 获取按钮宽度和高度
	int ButtonWidth = buttonSizeLocation.width;
	int ButtonHeight = buttonSizeLocation.height;

	// 获取按钮标签宽度和高度
	int ButtonTagWidth = textwidth(ButtonTag.c_str());
	int ButtonTagHeight = textheight(ButtonTag.c_str());

	// 计算按钮标签的居中坐标
	ButtonTagCenterX = (ButtonWidth - ButtonTagWidth) / 2 + buttonSizeLocation.x;
	ButtonTagCenterY = (ButtonHeight - ButtonTagHeight) / 2 + buttonSizeLocation.y;
}