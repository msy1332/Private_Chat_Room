//#include "TextBox.h"
//
//TextBox::TextBox()
//{
//	// ��ʼ���ı������ķ��
//	textBoxType = TextBoxType::Have_border_fill;
//
//	// ��ʼ���ı������Ľ���״̬
//	textBoxStatus = TextBoxStatus::Ordinary;
//
//	// ��ʼ���ı�������ģʽ
//	textBoxMode = TextBoxMode::Single_line;
//
//	// ��ʼ���ı��������ı�����ʽ
//	textStyle.flag = false;
//	textStyle.TextWidth = 0;
//	textStyle.TextHeigth = 35;
//
//	// ��ʼ���ı����������ֽ���״̬�µ���䣬������������ɫ
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
//	// ��ʼ���ı������Ĵ�С��λ�ú�Բ�ǵĿ�Ⱥ͸߶�
//	textBoxSizeLocation.x = 0;
//	textBoxSizeLocation.y = 0;
//	textBoxSizeLocation.width = 200;
//
//	// ��ʼ���ı������������ı��ַ����������
//	MaxLenFlag = false;
//	MaxTextWidthFlag = true;
//	MaxTextWidth = 150;
//
//	// �����ı��������ı��͹�������
//	CalculationTextCenteredCoordinate();
//	CalculationCursorCoordinate();
//}
//
//TextBox::TextBox(TextBox& textBox)
//{
//	// �����ı������ķ��
//	textBoxType = textBox.textBoxType;
//
//	// ��ʼ���ı�������ģʽ
//	textBoxMode = textBox.textBoxMode;
//
//	// �����ı��������ı�����ʽ
//	textStyle = textBox.textStyle;
//
//	// �����ı����������ֽ���״̬�µ���䣬������������ɫ
//	FillColor = textBox.FillColor;
//	LineColor = textBox.LineColor;
//	TextColor = textBox.TextColor;
//
//	// �����ı������Ĵ�С��λ�ú�Բ�ǵĿ�Ⱥ͸߶�
//	textBoxSizeLocation = textBox.textBoxSizeLocation;
//}
//
//TextBox::~TextBox()
//{
//}
//
//void TextBox::DrawCursor()
//{
//	static int LastTime = 0; // ������һ�����ͱ����������洢��һ�λ��ƹ���ʱ��
//	static int CurrentTime = 0; // ������һ�����ͱ����������洢��ǰʱ��
//	static int Interval = 500; // ������һ�����ͱ����������洢����ټ����˸һ�ι��
//	static bool Reveal = true; // ������һ������������������ʾ������ʾ״̬
//
//	CurrentTime = clock(); // ��ȡ��ǰʱ��
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
//		setlinecolor(BLACK); // ����������ɫ��Ҳ���ǹ�����ɫ
//		line(CursorX, CursorY, CursorX, CursorY + textStyle.TextHeigth); // ���ƹ��
//	}
//}
//
//void TextBox::DrawTextString()
//{
//	// �����ı�����ʽ
//	settextstyle(textStyle.TextHeigth, textStyle.TextWidth, L"����");
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
//	// �����ı�
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
//	ReadtUserInputString(msg); // ��ȡ�û�������ı�
//	CalculationTextCenteredCoordinate(); // �����ı��������ı��ľ�������
//	CalculationCursorCoordinate(); // ����������
//}
//
//void TextBox::CalculationTextCenteredCoordinate()
//{
//	// �����ı���ʽ���������������ʽ���ᵼ�¼���ľ�����������
//	settextstyle(textStyle.TextHeigth, textStyle.TextWidth,L"����");
//
//	// ��ȡ�ı������Ŀ�Ⱥ͸߶�
//	int textBoxWidth = textBoxSizeLocation.width;
//	int textBoxHeight = TextBoxHeight;
//
//	// ��ȡ�ı��ַ����Ŀ�Ⱥ͸߶�
//	int textWidth = (Text.empty() ? 0 : textwidth(Text.c_str()));
//	int textHeight = textStyle.TextHeigth;
//
//	// �����ı���������
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
//		wchar_t ch = (wchar_t)msg.wParam; // ��ȡ�û�������ַ���Ҳ���ǻ�ȡ�û�������ַ���Unicode���벢ǿ��ת�����ַ�
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