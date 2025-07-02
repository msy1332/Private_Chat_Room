#include "Button.h"

Button::Button() // Ĭ�Ϲ��캯����������ʼ����ť
{
	// ��ʼ����ť������
	buttonType = ButtonType::Have_border_fill;

	// ��ʼ����ť�ı�ǩ
	ButtonText = L"button";
	// std::wcout << "ButtonText: " << ButtonText << std::endl;

	// ��ʼ����ť�Ĵ�С��λ��
	buttonSizeLocation.x = 0;
	buttonSizeLocation.y = 0;
	buttonSizeLocation.width = 200;
	buttonSizeLocation.height = 50;

	// ���㰴ť��ǩ���ֵľ�������
	CalculationTextCenterLocation();

	// ��ʼ����ť�����ֵĽ���״̬�µ���䣬������������ɫ
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

Button::Button(Button& button) // Ĭ�Ϲ��캯����������ʼ����ť
{
	// ��ʼ����ť������
	buttonType = button.buttonType;

	// ��ʼ����ť�ı�ǩ
	ButtonText = button.ButtonText;

	// ��ʼ����ť�Ĵ�С��λ��
	buttonSizeLocation = button.buttonSizeLocation;

	// ��ʼ����ť�����ֵĽ���״̬�µ���䣬������������ɫ
	FillColor = button.FillColor;
	LineColor = button.LineColor;
	TextColor = button.TextColor;
}

Button::~Button() // ���������������ͷŰ�ť���õ�����Դ
{
	if (buttonType == ButtonType::Picture)
	{
		delete[] ButtonStatusIMagePATH;
		delete[] ButtonStatusIMage;
	}
}

void Button::SetButtonX(int x) // �������ð�ť��x����
{
	buttonSizeLocation.x = x;

	// ���¼��㰴ť��ǩ���ֵľ�������
	CalculationTextCenterLocation();
}

void Button::SetButtonY(int y) // �������ð�ť��y����
{
	buttonSizeLocation.y = y;

	// ���¼��㰴ť��ǩ���ֵľ�������
	CalculationTextCenterLocation();
}

void Button::SetText(std::wstring Text) // �������ð�ť�ı�ǩ
{
	ButtonText = Text;

	// ���¼��㰴ť��ǩ���ֵľ�������
	CalculationTextCenterLocation();
}

void Button::SetButtonType(ButtonType buttonType) // �������ð�ť�ķ��Ҳ���ǰ�ť������
{
	this->buttonType = buttonType;
}

void Button::SetFillColor(ButtonStatusColor FillColor) // ���°�ť�����ֵĽ���״̬�µ������ɫ
{
	this->FillColor = FillColor;
}

void Button::SetLineColor(ButtonStatusColor LineColor) // ���°�ť�����ֵĽ���״̬�µ�������ɫ
{
	this->LineColor = LineColor;
}

void Button::SetTextColor(ButtonStatusColor TextColor) // ���°�ť�����ֵĽ���״̬�µ�������ɫ
{
	this->TextColor = TextColor;
}

void Button::SetButtonStatusIMagePATH(const std::wstring* ButtonStatusIMagePATH) // ���ð�ť�����ֲ�ͬ�Ľ���״̬�µ�ͼƬ��·��
{
	ButtonStatusIMage = new IMAGE[3];
	for (int i = 0; i < 3; i++)
	{
		loadimage(&ButtonStatusIMage[i], ButtonStatusIMagePATH[i].c_str());
	}

	// ��ʼ����ť�Ŀ�Ⱥ͸߶�
	buttonSizeLocation.width = ButtonStatusIMage[0].getwidth();
	buttonSizeLocation.height = ButtonStatusIMage[0].getheight();
}

void Button::SetButtonStatusIMage(const IMAGE* ButtonStatusIMage) // ���ð�ť�����ֲ�ͬ�Ľ���״̬�µ�ͼƬ
{
	this->ButtonStatusIMage = new IMAGE[3];
	for (int i = 0; i < 3; i++)
	{
		this->ButtonStatusIMage[i] = ButtonStatusIMage[i];
	}

	// ��ʼ����ť�Ŀ�Ⱥ͸߶�
	buttonSizeLocation.width = this->ButtonStatusIMage[0].getwidth();
	buttonSizeLocation.height = this->ButtonStatusIMage[0].getheight();
}


void Button::SetButtonSizeLocation(ButtonSizeLocation buttonSizeLocation) // �������ð�ť�Ĵ�С��λ�ú�Բ�ǵĿ�Ⱥ͸߶�
{
	this->buttonSizeLocation = buttonSizeLocation;
}


void Button::Draw() // ��д�˽ӿ���Ļ���UI(Draw)�ĺ������������ư�ť
{
	switch (buttonType)
	{
		case ButtonType::Have_border_fill: // ���߿����䰴ť
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
		case ButtonType::Borderless_fill: // �����߿����䰴ť
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
		case ButtonType::Have_border_fill_rounded: // ���߿�����Բ�ǰ�ť
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
		case ButtonType::Borderless_fill_rounded: // �����߿�����Բ�ǰ�ť
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
		case ButtonType::Picture: // ͼƬ��ť
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

UISignal Button::Updata(ExMessage msg) // ��д�˽ӿ���ĸ���UI(Updata)�������������°�ť��״̬
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

bool Button::JudgmentMouseInside(int MouseX, int MouseY) // �ж�����Ƿ��ڰ�ť����
{
	if (MouseX > buttonSizeLocation.x && MouseX < buttonSizeLocation.x + buttonSizeLocation.width && MouseY > buttonSizeLocation.y && MouseY < buttonSizeLocation.y + buttonSizeLocation.height)
		return 1;
	else
		return 0;
}

void Button::CalculationTextCenterLocation()
{
	// ��ȡ��ť��ǩ���ֵĿ�Ⱥ͸߶�
	int TextWidth = textwidth(ButtonText.c_str());
	int TextHeight = textheight(ButtonText.c_str());
	// std::cout << "TextWidth: " << TextWidth << "\t" << "TextHeight: " << TextHeight << std::endl;

	// ��ȡ��ť�Ŀ�Ⱥ͸߶�
	int ButtonWidth = buttonSizeLocation.width;
	int ButtonHeight = buttonSizeLocation.height;
	// std::cout << "ButtonWidth: " << ButtonWidth << "\t" << "ButtonHeight: " << ButtonHeight << std::endl;

	// ���㰴ť��ǩ���ֵľ�������
	TextCenterX = (ButtonWidth - TextWidth) / 2 + buttonSizeLocation.x;
	TextCenterY = (ButtonHeight - TextHeight) / 2 + buttonSizeLocation.y;
	// std::cout << "TextCenterX: " << TextCenterX << "\t" << "TextCenterY: " << TextCenterY << std::endl;
}