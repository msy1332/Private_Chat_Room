#include "Button.h" // ������ťģ��Ķ���ͷ�ļ�
using namespace UIControl; // ʹ��UIControl�����ռ�

Button::Button()
{
	// �������ť�ؼ�����һ��ΨһID
	if (FlagID == false) // �жϰ�ť�ؼ��Ƿ������ΨһID,���û����Ļᣬ������һ��ΨһID,���򲻷���
	{
		ID = CounterID++;
		FlagID = true;
	}

	// ��ʼ����ť�ķ��
	buttonType = ButtonType::With_borders_Fill_Button;

	// ��ʼ����ť����״̬
	buttonStatus = ButtonStatus::Ordinary;

	// ��ʼ����ť�������ֲ�ͬ�Ľ���״̬�µ���䣬�����Ͱ�ť��ǩ����ɫ
	FillColor.Ordinary = RGB(225, 225, 225);
	FillColor.Suspended = RGB(229, 241, 251);
	FillColor.Press = RGB(204, 228, 247);

	LineColor.Ordinary = RGB(173, 173, 173);
	LineColor.Suspended = RGB(0, 120, 215);
	LineColor.Press = RGB(0, 84, 153);

	TextColor.Ordinary = RGB(0, 0, 0);
	TextColor.Suspended = RGB(0, 0, 0);
	TextColor.Press = RGB(0, 0, 0);

	// ��ʼ����ť��С��λ��
	buttonSizeLocation.x = 0;
	buttonSizeLocation.y = 0;
	buttonSizeLocation.width = 200; 
	buttonSizeLocation.height = 50;

	// ��ʼ����ť��ǩ
	buttonTagStyle.height = 20;
	buttonTagStyle.width = 0;
	buttonTagStyle.Font = L"����";
	ButtonTag = L"button" + std::to_wstring(ID);
	CalculationButtonTagCenterCoordinate(); // ���㰴ť��ǩ��������
}

Button::Button(const Button& button)
{
	// �������ť�ؼ�����һ��ΨһID
	if (FlagID == false) // �жϰ�ť�ؼ��Ƿ������ΨһID,���û����Ļᣬ������һ��ΨһID,���򲻷���
	{
		ID = CounterID++;
		FlagID = true;
	}

	// ������ť�ķ��
	buttonType = button.buttonType;

	// ��ʼ����ť����״̬
	buttonStatus = ButtonStatus::Ordinary;

	// ������ť�������ֲ�ͬ�Ľ���״̬�µ���䣬�����Ͱ�ť��ǩ����ɫ
	FillColor = button.FillColor;
	LineColor = button.LineColor;
	TextColor = button.TextColor;

	// ������ť��С��λ��
	buttonSizeLocation = button.buttonSizeLocation;

	// ��ʼ����ť��ǩ
	ButtonTag = L"button" + ID;
}

Button::~Button()
{
	delete[] ButtonStatusImage; // �ͷŰ�ť���õ���ͼƬ��Դ
}

void Button::SetButtonType(ButtonType buttonType) // �������ð�ť�ķ��
{
	this->buttonType = buttonType;
}

void Button::SetButtonTag(std::wstring ButtonTag) // �������ð�ť�ı�ǩ
{
	this->ButtonTag = ButtonTag;
}

void Button::SetButtonTagStyle(ButtonTagStyle buttonTagStyle) // �������ð�ť��ǩ��ʽ��Ҳ���������ť��ǩ�ı���С������
{
	this->buttonTagStyle = buttonTagStyle;
	CalculationButtonTagCenterCoordinate(); // ���¼��㰴ť��ǩ��������
}

void Button::SetButtonStatusFill(ButtonStatusColor FillColor) // �������ð�ť�����ֵĽ���״̬�µĲ�ͬ�����ɫ
{
	this->FillColor = FillColor;
}

void Button::SetButtonStatusLine(ButtonStatusColor LineColor) // �������ð�ť�����ֵĽ���״̬�µĲ�ͬ������ɫ
{
	this->LineColor = LineColor;
}

void Button::SetButtonStatusText(ButtonStatusColor TextColor) // �������ð�ť�����ֵĽ���״̬�µĲ�ͬ������ɫ��Ҳ���ǰ�ť��ǩ����ɫ
{
	this->TextColor = TextColor;
}

void Button::SetButtonLocation(int x, int y) // �������ð�ťλ��
{
	this->buttonSizeLocation.x = x;
	this->buttonSizeLocation.y = y;
	CalculationButtonTagCenterCoordinate(); // ���¼��㰴ť��ǩ��������
}

void Button::SetButtonSize(int width, int height) // �������ð�ť�Ĵ�С
{
	this->buttonSizeLocation.width = width;
	this->buttonSizeLocation.height = height;
	CalculationButtonTagCenterCoordinate(); // ���¼��㰴ť��ǩ��������
}

void Button::SetButtonSizeLocation(ButtonSizeLocation buttonSizeLocation) // �������ð�ť�Ĵ�С��λ��
{
	this->buttonSizeLocation = buttonSizeLocation;
	CalculationButtonTagCenterCoordinate(); // ���¼��㰴ť��ǩ��������
}

void Button::SetButtonImage(IMAGE* img) // ����ͼƬ��ť�����ֽ���״̬�µĲ�ͬ�İ�ťͼƬ
{
	ButtonStatusImage = new IMAGE[3]; // ����ռ�

	for (int i = 0; i < 3; i++) // �������ťͼƬ��������
		ButtonStatusImage[i] = img[i];

	// ���³�ʼ����ť��Ⱥ͸߶�
	buttonSizeLocation.width = ButtonStatusImage[0].getwidth();
	buttonSizeLocation.height = ButtonStatusImage[0].getheight();
}

void Button::SetButtonImagePath(std::wstring* path) // ����ͼƬ��ť�����ֽ���״̬�µĲ�ͬ��ťͼƬ��·��
{
	ButtonStatusImage = new IMAGE[3]; // ����ռ�

	for (int i = 0; i < 3; i++) // �������ťͼƬ���ع���
		loadimage(&ButtonStatusImage[i], path[i].c_str());

	// ���³�ʼ����ť��Ⱥ͸߶�
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

			// ���ð�ť��ǩ��ʽ��Ҳ���Ǳ�ǩ�ı��Ĵ�С������
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

			// ���ð�ť��ǩ��ʽ��Ҳ���Ǳ�ǩ�ı��Ĵ�С������
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

			// ���ð�ť��ǩ��ʽ��Ҳ���Ǳ�ǩ�ı��Ĵ�С������
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

			// ���ð�ť��ǩ��ʽ��Ҳ���Ǳ�ǩ�ı��Ĵ�С������
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
	// ���ð�ť��ǩ��ʽ��Ҳ���Ǳ�ǩ�ı��Ĵ�С������
	settextstyle(buttonTagStyle.height, buttonTagStyle.width, buttonTagStyle.Font.c_str());

	// ��ȡ��ť��Ⱥ͸߶�
	int ButtonWidth = buttonSizeLocation.width;
	int ButtonHeight = buttonSizeLocation.height;

	// ��ȡ��ť��ǩ��Ⱥ͸߶�
	int ButtonTagWidth = textwidth(ButtonTag.c_str());
	int ButtonTagHeight = textheight(ButtonTag.c_str());

	// ���㰴ť��ǩ�ľ�������
	ButtonTagCenterX = (ButtonWidth - ButtonTagWidth) / 2 + buttonSizeLocation.x;
	ButtonTagCenterY = (ButtonHeight - ButtonTagHeight) / 2 + buttonSizeLocation.y;
}