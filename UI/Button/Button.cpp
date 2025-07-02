#include "Button.h"

Button::Button() // 默认构造函数，用来初始化按钮
{
	// 初始化按钮的类型
	buttonType = ButtonType::Have_border_fill;

	// 初始化按钮的标签
	ButtonText = L"button";
	// std::wcout << "ButtonText: " << ButtonText << std::endl;

	// 初始化按钮的大小和位置
	buttonSizeLocation.x = 0;
	buttonSizeLocation.y = 0;
	buttonSizeLocation.width = 200;
	buttonSizeLocation.height = 50;

	// 计算按钮标签文字的居中坐标
	CalculationTextCenterLocation();

	// 初始化按钮在三种的交互状态下的填充，线条和文字颜色
	FillColor.Ordinary = RGB(225, 225, 225);
	FillColor.Suspended = RGB(229, 241, 251);
	FillColor.Press = RGB(204, 228, 247);

	LineColor.Ordinary = RGB(173, 173, 173);
	LineColor.Suspended = RGB(0, 120, 215);
	LineColor.Press = RGB(0, 84, 153);

	TextColor.Ordinary = RGB(0, 0, 0);
	TextColor.Suspended = RGB(0, 0, 0);
	TextColor.Press = RGB(0, 0, 0);
}

Button::Button(Button& button) // 默认构造函数，用来初始化按钮
{
	// 初始化按钮的类型
	buttonType = button.buttonType;

	// 初始化按钮的标签
	ButtonText = button.ButtonText;

	// 初始化按钮的大小和位置
	buttonSizeLocation = button.buttonSizeLocation;

	// 初始化按钮在三种的交互状态下的填充，线条和文字颜色
	FillColor = button.FillColor;
	LineColor = button.LineColor;
	TextColor = button.TextColor;
}

Button::~Button() // 析构函数，用来释放按钮所用到的资源
{
	if (buttonType == ButtonType::Picture)
	{
		delete[] ButtonStatusIMagePATH;
		delete[] ButtonStatusIMage;
	}
}

void Button::SetButtonX(int x) // 重新设置按钮的x坐标
{
	buttonSizeLocation.x = x;

	// 重新计算按钮标签文字的居中坐标
	CalculationTextCenterLocation();
}

void Button::SetButtonY(int y) // 重新设置按钮的y坐标
{
	buttonSizeLocation.y = y;

	// 重新计算按钮标签文字的居中坐标
	CalculationTextCenterLocation();
}

void Button::SetText(std::wstring Text) // 重新设置按钮的标签
{
	ButtonText = Text;

	// 重新计算按钮标签文字的居中坐标
	CalculationTextCenterLocation();
}

void Button::SetButtonType(ButtonType buttonType) // 重新设置按钮的风格，也就是按钮的类型
{
	this->buttonType = buttonType;
}

void Button::SetFillColor(ButtonStatusColor FillColor) // 重新按钮在三种的交互状态下的填充颜色
{
	this->FillColor = FillColor;
}

void Button::SetLineColor(ButtonStatusColor LineColor) // 重新按钮在三种的交互状态下的线条颜色
{
	this->LineColor = LineColor;
}

void Button::SetTextColor(ButtonStatusColor TextColor) // 重新按钮在三种的交互状态下的文字颜色
{
	this->TextColor = TextColor;
}

void Button::SetButtonStatusIMagePATH(const std::wstring* ButtonStatusIMagePATH) // 设置按钮在三种不同的交互状态下的图片的路径
{
	ButtonStatusIMage = new IMAGE[3];
	for (int i = 0; i < 3; i++)
	{
		loadimage(&ButtonStatusIMage[i], ButtonStatusIMagePATH[i].c_str());
	}

	// 初始化按钮的宽度和高度
	buttonSizeLocation.width = ButtonStatusIMage[0].getwidth();
	buttonSizeLocation.height = ButtonStatusIMage[0].getheight();
}

void Button::SetButtonStatusIMage(const IMAGE* ButtonStatusIMage) // 设置按钮在三种不同的交互状态下的图片
{
	this->ButtonStatusIMage = new IMAGE[3];
	for (int i = 0; i < 3; i++)
	{
		this->ButtonStatusIMage[i] = ButtonStatusIMage[i];
	}

	// 初始化按钮的宽度和高度
	buttonSizeLocation.width = this->ButtonStatusIMage[0].getwidth();
	buttonSizeLocation.height = this->ButtonStatusIMage[0].getheight();
}


void Button::SetButtonSizeLocation(ButtonSizeLocation buttonSizeLocation) // 重新设置按钮的大小，位置和圆角的宽度和高度
{
	this->buttonSizeLocation = buttonSizeLocation;
}


void Button::Draw() // 重写了接口类的绘制UI(Draw)的函数，用来绘制按钮
{
	switch (buttonType)
	{
		case ButtonType::Have_border_fill: // 带边框的填充按钮
			switch (buttonStatus)
			{
				case ButtonStatus::Ordinary:
					setfillcolor(FillColor.Ordinary);
					setlinecolor(LineColor.Ordinary);
					settextcolor(TextColor.Ordinary);
					fillrectangle(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
				case ButtonStatus::Suspended:
					setfillcolor(FillColor.Suspended); 
					setlinecolor(LineColor.Suspended);
					settextcolor(TextColor.Suspended);
					fillrectangle(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
				case ButtonStatus::Press:
					setfillcolor(FillColor.Press);
					setlinecolor(LineColor.Press);
					settextcolor(TextColor.Press);
					fillrectangle(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
			}
		break;
		case ButtonType::Borderless_fill: // 不带边框的填充按钮
			switch (buttonStatus)
			{
				case ButtonStatus::Ordinary:
					setfillcolor(FillColor.Ordinary);
					setlinecolor(FillColor.Ordinary);
					settextcolor(TextColor.Ordinary);
					fillrectangle(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
				case ButtonStatus::Suspended:
					setfillcolor(FillColor.Suspended);
					setlinecolor(FillColor.Suspended);
					settextcolor(TextColor.Suspended);
					fillrectangle(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
				case ButtonStatus::Press:
					setfillcolor(FillColor.Press);
					setlinecolor(FillColor.Press);
					settextcolor(TextColor.Press);
					fillrectangle(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
			}
		break;
		case ButtonType::Have_border_fill_rounded: // 带边框的填充圆角按钮
			switch (buttonStatus)
			{
				case ButtonStatus::Ordinary:
					setfillcolor(FillColor.Ordinary);
					setlinecolor(LineColor.Ordinary);
					settextcolor(TextColor.Ordinary);
					fillroundrect(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height, buttonSizeLocation.ellipsewidth, buttonSizeLocation.ellipseheight);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
				case ButtonStatus::Suspended:
					setfillcolor(FillColor.Suspended);
					setlinecolor(LineColor.Suspended);
					settextcolor(TextColor.Suspended);
					fillroundrect(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height, buttonSizeLocation.ellipsewidth, buttonSizeLocation.ellipseheight);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
				case ButtonStatus::Press:
					setfillcolor(FillColor.Press);
					setlinecolor(LineColor.Press);
					settextcolor(TextColor.Press);
					fillroundrect(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height, buttonSizeLocation.ellipsewidth, buttonSizeLocation.ellipseheight);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
			}
		break;
		case ButtonType::Borderless_fill_rounded: // 不带边框的填充圆角按钮
			switch (buttonStatus)
			{
				case ButtonStatus::Ordinary:
					setfillcolor(FillColor.Ordinary);
					settextcolor(TextColor.Ordinary);
					solidroundrect(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height, buttonSizeLocation.ellipsewidth, buttonSizeLocation.ellipseheight);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
				case ButtonStatus::Suspended:
					setfillcolor(FillColor.Suspended);
					settextcolor(TextColor.Suspended);
					solidroundrect(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height, buttonSizeLocation.ellipsewidth, buttonSizeLocation.ellipseheight);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
				case ButtonStatus::Press:
					setfillcolor(FillColor.Press);
					settextcolor(TextColor.Press);
					solidroundrect(buttonSizeLocation.x, buttonSizeLocation.y, buttonSizeLocation.x + buttonSizeLocation.width, buttonSizeLocation.y + buttonSizeLocation.height, buttonSizeLocation.ellipsewidth, buttonSizeLocation.ellipseheight);
					outtextxy(TextCenterX, TextCenterY, ButtonText.c_str());
					break;
			}
		break;
		case ButtonType::Picture: // 图片按钮
			switch (buttonStatus)
			{
				case ButtonStatus::Ordinary:
					putimage(buttonSizeLocation.x, buttonSizeLocation.y, &ButtonStatusIMage[0]);
					break;
				case ButtonStatus::Suspended:
					putimage(buttonSizeLocation.x, buttonSizeLocation.y, &ButtonStatusIMage[1]);
					break;
				case ButtonStatus::Press:
					putimage(buttonSizeLocation.x, buttonSizeLocation.y, &ButtonStatusIMage[2]);
					break;
			}
		break;
	}
}

UISignal Button::Updata(ExMessage msg) // 重写了接口类的更新UI(Updata)函数，用来更新按钮的状态
{
	if (JudgmentMouseInside(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		buttonStatus = ButtonStatus::Press;
		return UISignal::Click;
	}
	else if (JudgmentMouseInside(msg.x, msg.y))
	{
		buttonStatus = ButtonStatus::Suspended;
	}
	else
	{
		buttonStatus = ButtonStatus::Ordinary;
	}
}

bool Button::JudgmentMouseInside(int MouseX, int MouseY) // 判断鼠标是否在按钮里面
{
	if (MouseX > buttonSizeLocation.x && MouseX < buttonSizeLocation.x + buttonSizeLocation.width && MouseY > buttonSizeLocation.y && MouseY < buttonSizeLocation.y + buttonSizeLocation.height)
		return 1;
	else
		return 0;
}

void Button::CalculationTextCenterLocation()
{
	// 获取按钮标签文字的宽度和高度
	int TextWidth = textwidth(ButtonText.c_str());
	int TextHeight = textheight(ButtonText.c_str());
	// std::cout << "TextWidth: " << TextWidth << "\t" << "TextHeight: " << TextHeight << std::endl;

	// 获取按钮的宽度和高度
	int ButtonWidth = buttonSizeLocation.width;
	int ButtonHeight = buttonSizeLocation.height;
	// std::cout << "ButtonWidth: " << ButtonWidth << "\t" << "ButtonHeight: " << ButtonHeight << std::endl;

	// 计算按钮标签文字的居中坐标
	TextCenterX = (ButtonWidth - TextWidth) / 2 + buttonSizeLocation.x;
	TextCenterY = (ButtonHeight - TextHeight) / 2 + buttonSizeLocation.y;
	// std::cout << "TextCenterX: " << TextCenterX << "\t" << "TextCenterY: " << TextCenterY << std::endl;
}