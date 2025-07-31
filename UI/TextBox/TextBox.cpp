//#include "TextBox.h"
//
//TextBox::TextBox()
//{
//	// 初始化文本输入框的风格
//	textBoxType = TextBoxType::Have_border_fill;
//
//	// 初始化文本输入框的交互状态
//	textBoxStatus = TextBoxStatus::Ordinary;
//
//	// 初始化文本输入框的模式
//	textBoxMode = TextBoxMode::Single_line;
//
//	// 初始化文本输入框的文本的样式
//	textStyle.flag = false;
//	textStyle.TextWidth = 0;
//	textStyle.TextHeigth = 35;
//
//	// 初始化文本输入框的三种交互状态下的填充，线条，文字颜色
//	FillColor.Ordinary = RGB(255, 255, 255);
//	FillColor.Suspended = RGB(255, 255, 255);
//	FillColor.Input = RGB(255, 255, 255);
//
//	LineColor.Ordinary = RGB(122, 122, 122);
//	LineColor.Suspended = RGB(23, 23, 23);
//	LineColor.Input = RGB(240, 240, 240);
//
//	TextColor.Ordinary = BLACK;
//	TextColor.Suspended = BLACK;
//	TextColor.Input = BLACK;
//
//	// 初始化文本输入框的大小，位置和圆角的宽度和高度
//	textBoxSizeLocation.x = 0;
//	textBoxSizeLocation.y = 0;
//	textBoxSizeLocation.width = 200;
//
//	// 初始化文本输入框输入的文本字符串的最大宽度
//	MaxLenFlag = false;
//	MaxTextWidthFlag = true;
//	MaxTextWidth = 150;
//
//	// 计算文本输入框的文本和光标的坐标
//	CalculationTextCenteredCoordinate();
//	CalculationCursorCoordinate();
//}
//
//TextBox::TextBox(TextBox& textBox)
//{
//	// 拷贝文本输入框的风格
//	textBoxType = textBox.textBoxType;
//
//	// 初始化文本输入框的模式
//	textBoxMode = textBox.textBoxMode;
//
//	// 拷贝文本输入框的文本的样式
//	textStyle = textBox.textStyle;
//
//	// 拷贝文本输入框的三种交互状态下的填充，线条，文字颜色
//	FillColor = textBox.FillColor;
//	LineColor = textBox.LineColor;
//	TextColor = textBox.TextColor;
//
//	// 拷贝文本输入框的大小，位置和圆角的宽度和高度
//	textBoxSizeLocation = textBox.textBoxSizeLocation;
//}
//
//TextBox::~TextBox()
//{
//}
//
//void TextBox::DrawCursor()
//{
//	static int LastTime = 0; // 定义了一个整型变量，用来存储上一次绘制光标的时间
//	static int CurrentTime = 0; // 定义了一个整型变量，用来存储当前时间
//	static int Interval = 500; // 定义了一个整型变量，用来存储格多少间隔闪烁一次光标
//	static bool Reveal = true; // 定义了一个布尔变量，用来表示光标的显示状态
//
//	CurrentTime = clock(); // 获取当前时间
//	if (CurrentTime - LastTime >= Interval)
//	{
//		if (Reveal)
//			Reveal = false;
//		else
//			Reveal = true;
//	}
//
//	if (Reveal)
//	{
//		setlinecolor(BLACK); // 设置线条颜色，也就是光标的颜色
//		line(CursorX, CursorY, CursorX, CursorY + textStyle.TextHeigth); // 绘制光标
//	}
//}
//
//void TextBox::DrawTextString()
//{
//	// 设置文本的样式
//	settextstyle(textStyle.TextHeigth, textStyle.TextWidth, L"宋体");
//
//	switch (textBoxStatus)
//	{
//		case TextBoxStatus::Ordinary:
//			settextcolor(TextColor.Ordinary);
//			break;
//		case TextBoxStatus::Suspended:
//			settextcolor(TextColor.Suspended);
//			break;
//		case TextBoxStatus::Input:
//			settextcolor(TextColor.Input);
//			break;
//	}
//
//	// 绘制文本
//	outtextxy(CenterX, CenterY, Text.c_str());
//}
//
//void TextBox::Draw()
//{
//	switch (textBoxType)
//	{
//		case TextBoxType::Have_border_fill:
//			switch (textBoxStatus)
//			{
//				case TextBoxStatus::Ordinary:
//					setfillcolor(FillColor.Ordinary);
//					setlinecolor(LineColor.Ordinary);
//					fillrectangle(textBoxSizeLocation.x, textBoxSizeLocation.y, textBoxSizeLocation.x + textBoxSizeLocation.width, textBoxSizeLocation.y + TextBoxHeight);
//					DrawTextString();
//					break;
//				case TextBoxStatus::Suspended:
//					setfillcolor(FillColor.Suspended);
//					setlinecolor(LineColor.Suspended);
//					fillrectangle(textBoxSizeLocation.x, textBoxSizeLocation.y, textBoxSizeLocation.x + textBoxSizeLocation.width, textBoxSizeLocation.y + TextBoxHeight);
//					DrawTextString();
//					break;
//				case TextBoxStatus::Input:
//					setfillcolor(FillColor.Input);
//					setlinecolor(LineColor.Input);
//					fillrectangle(textBoxSizeLocation.x, textBoxSizeLocation.y, textBoxSizeLocation.x + textBoxSizeLocation.width, textBoxSizeLocation.y + TextBoxHeight);
//					DrawTextString();
//					DrawCursor();
//					break;
//			}
//			break;
//		case TextBoxType::Borderless_fill:
//			break;
//		case TextBoxType::Have_border_fill_rounded:
//			break;
//		case TextBoxType::Borderless_fill_rounded:
//			break;
//	}
//}
//
//UISignal TextBox::Updata(ExMessage msg)
//{	
//	if (JudgmentMouseInside(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
//	{
//		textBoxStatus = TextBoxStatus::Input;
//		return UISignal::Click;
//	}
//	else if (JudgmentMouseInside(msg.x, msg.y) && textBoxStatus != TextBoxStatus::Input)
//	{
//		textBoxStatus = TextBoxStatus::Suspended;
//	}
//	else if (textBoxStatus != TextBoxStatus::Input)
//	{
//		textBoxStatus = TextBoxStatus::Ordinary;
//	}
//
//	ReadtUserInputString(msg); // 读取用户输入的文本
//	CalculationTextCenteredCoordinate(); // 计算文本输入框的文本的居中坐标
//	CalculationCursorCoordinate(); // 计算光标坐标
//}
//
//void TextBox::CalculationTextCenteredCoordinate()
//{
//	// 设置文本样式，，如果不设置样式，会导致计算的居中坐标很奇怪
//	settextstyle(textStyle.TextHeigth, textStyle.TextWidth,L"宋体");
//
//	// 获取文本输入框的宽度和高度
//	int textBoxWidth = textBoxSizeLocation.width;
//	int textBoxHeight = TextBoxHeight;
//
//	// 获取文本字符串的宽度和高度
//	int textWidth = (Text.empty() ? 0 : textwidth(Text.c_str()));
//	int textHeight = textStyle.TextHeigth;
//
//	// 计算文本居中坐标
//	CenterX = ((textBoxWidth - (textStyle.flag == 0 ? MaxTextWidth : CurrentTextWidth)) / 2) + textBoxSizeLocation.x;
//	CenterY = ((textBoxHeight - textHeight) / 2) + textBoxSizeLocation.y;
//}
//
//void TextBox::CalculationCursorCoordinate()
//{
//	if (Text.empty())
//	{
//		CursorX = CenterX;
//		CursorY = CenterY;
//	}
//	else
//	{
//		CursorX = CenterX + CurrentTextWidth;
//		CursorY = CenterY;
//	}
//}
//
//void TextBox::ReadtUserInputString(ExMessage msg)
//{
//	if (textBoxStatus == TextBoxStatus::Input)
//	{
//		wchar_t ch = (wchar_t)msg.wParam; // 获取用户输入的字符，也就是获取用户输入的字符的Unicode编码并强制转换成字符
//		if (ch == '\b' && !Text.empty())
//		{
//			CurrentLen--;
//			CurrentTextWidth -= textwidth(Text.back());
//			Text.pop_back();
//		}
//		else if(((MaxLenFlag == true && CurrentLen <= MaxLen) || (MaxTextWidthFlag == true && CurrentTextWidth <= MaxTextWidth)) && ch != '\n' && ch != '\r' && ch != '\b')
//		{
//			Text.push_back(ch);
//			CurrentLen++;
//			CurrentTextWidth += textwidth(ch);
//		}
//	}
//}
//
//bool TextBox::JudgmentMouseInside(int MouseX, int MouseY)
//{
//	if (MouseX > textBoxSizeLocation.x && MouseX < textBoxSizeLocation.x + textBoxSizeLocation.width && MouseY > textBoxSizeLocation.y && MouseY < textBoxSizeLocation.y + TextBoxHeight)
//		return 1;
//	else
//		return 0;
//}