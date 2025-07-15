#pragma once // ��ֹͷ�ļ��ظ�����
#include <Windows.h> // ����windowsAPIͷ�ļ�
#include <iostream> // ������׼�������ͷ�ļ�
#include <easyx.h> // ����easyxͼ�ο�
#include <string> // �����ַ���(string)���ͷ�ļ�
#include "../UI.h" // ����UI�ӿ����ͷ�ļ�
#include "../../Tool/Tool.h" // ��������ͷ�ļ�

enum class ButtonType // ������һ��ǿö�����ͣ�������ʾ��ͬ���İ�ť����
{
	Have_border_fill,            // ���߿����䰴ť
	Borderless_fill,             // �����߿����䰴ť
	Have_border_fill_rounded,    // ���߿�����Բ�ǰ�ť
	Borderless_fill_rounded,     // �����߿�����Բ�ǰ�ť
	Picture                      // ͼƬ��ť
};

enum class ButtonStatus // ������һ��ǿö�����ͣ�������ʾ��ǰ��ť�Ľ���״̬
{
	Ordinary,	// ��ͨ״̬
	Suspended,	// ����״̬
	Press		// ����״̬
};

struct ButtonStatusColor // ����һ���ṹ�壬������ʾ��ť��������ֽ���״̬�µ���ɫ����
{
	COLORREF Ordinary;	// ��ͨ״̬�µ���ɫ
	COLORREF Suspended;	// ����״̬�µ���ɫ
	COLORREF Press;		// ����״̬�µ���ɫ
};

struct ButtonSizeLocation // ������һ���ṹ�壬������ʾ��ť�Ĵ�С��λ�ú�Բ�ǳߴ�
{
	int x;				// ��ť��x����
	int y;				// ��ť��y����
	int width;			// ��ť�Ŀ��
	int height;			// ��ť�ĸ߶�
	int ellipsewidth;	// ��ťԲ�ǵĿ��
	int ellipseheight;	// ��ťԲ�ǵĸ߶�
};

class Button : public UI // ������һ����ť��UI�࣬���̳����UI�Ľӿ���
{
	public:
		Button(); // Ĭ�Ϲ��캯����������ʼ����ť
		Button(Button& button); // �������캯����������ʼ����ť
		~Button(); // ���������������ͷŰ�ť���õ�����Դ

		void SetButtonX(int x); // �������ð�ť��x����
		void SetButtonY(int y); // �������ð�ť��y����
		void SetText(std::wstring Text); // �������ð�ť�ı�ǩ
		void SetButtonType(ButtonType buttonType); // �������ð�ť�ķ��Ҳ���ǰ�ť������
		void SetFillColor(ButtonStatusColor FillColor); // ���°�ť�����ֵĽ���״̬�µ������ɫ
		void SetLineColor(ButtonStatusColor LineColor); // ���°�ť�����ֵĽ���״̬�µ������ɫ
		void SetTextColor(ButtonStatusColor TextColor); // ���°�ť�����ֵĽ���״̬�µ������ɫ
		void SetButtonStatusIMagePATH(const std::wstring* ButtonStatusIMagePATH); // ���ð�ť�����ֲ�ͬ�Ľ���״̬�µ�ͼƬ��·��
		void SetButtonStatusIMage(const IMAGE* ButtonStatusIMage); // ���ð�ť�����ֲ�ͬ�Ľ���״̬�µ�ͼƬ
		void SetButtonSizeLocation(ButtonSizeLocation buttonSizeLocation); // �������ð�ť�Ĵ�С��λ�ú�Բ�ǵĿ�Ⱥ͸߶�

		void Draw() override; // ��д�˽ӿ���Ļ���UI(Draw)�ĺ������������ư�ť
		UISignal Updata(ExMessage msg) override; // ��д�˽ӿ���ĸ���UI(Updata)�������������°�ť��״̬
		bool JudgmentMouseInside(int MouseX, int MouseY); // �ж�����Ƿ��ڰ�ť����
		void CalculationTextCenterLocation(); // ���㰴ť��ǩ�ľ�������
	private:
		Tool tool; // ʵ����һ�����߶��󣬲�ͨ������������������͸����ͼ����

		int TextCenterX; // ��ť��ǩ���е�x
		int TextCenterY; // ��ť��ǩ���е�y

		std::wstring ButtonText; // ������һ���ַ����������洢��ť�ı�ǩ��Ҳ������ʾ�ڰ�ť���������
		ButtonType buttonType; // ������һ��ö�ٱ�����������ʾ��ť�ķ��
		ButtonStatus buttonStatus; // ������һ��ö�ٱ�����������ʾ��ǰ��ť�Ľ���״̬
		
		std::string* ButtonStatusIMagePATH; // ������һ��string�ַ������������洢��ť�����ֲ�ͬ�Ľ���״̬�µ�ͼƬ��·��
		IMAGE* ButtonStatusIMage; // ������һ��IMAGE���������洢��ť�����ֲ�ͬ�Ľ���״̬�µ�ͼƬ
		ButtonStatusColor FillColor; // ����һ���ṹ������������洢��ť�ڲ�ͬ�Ľ���״̬�µ������ɫ
		ButtonStatusColor LineColor; // ����һ���ṹ������������洢��ť�ڲ�ͬ�Ľ���״̬�µ�������ɫ
		ButtonStatusColor TextColor; // ����һ���ṹ������������洢��ť�ڲ�ͬ�Ľ���״̬�µ�������ɫ

		ButtonSizeLocation buttonSizeLocation; // ������һ���ṹ������������洢��ť�Ĵ�С��λ�ú�Բ�ǵĿ�Ⱥ͸߶�
};