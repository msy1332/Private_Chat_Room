#pragma once // ��ֹͷ�ļ��ظ�����
#include <iostream> // ������׼�������ͷ�ļ�
#include <easyx.h> // ����easyxͼ�ο�ͷ�ļ�
#include <string> // ����string�ַ�����ͷ�ļ�
#include "../UI.h" // ����UI�ӿ���ͷ�ļ�
#include "../../Tool/Tool.h" // ����Tool����ͷ�ļ�

namespace UIControl // ������һ��UI�ؼ������ռ䣬Ϊ�˷�ֹ������ͻ
{
	enum class ButtonType // ������һ��ǿö���࣬������ʾ��ͬ���İ�ť������
	{
		With_borders_Fill_Button,				// ���߿����䰴ť
		Without_borders_Fill_Button,			// �����߿����䰴ť
		With_borders_Fill_Rounded_Button,		// ���߿�����Բ�ǰ�ť
		Without_borders_Fill_Rounded_Button,	// �����߿�����Բ�ǰ�ť
		Picture_Button							// ͼƬ��ť
	};

	enum class ButtonStatus // ������һ��ǿö���࣬������ʾ��ť�����ֲ�ͬ�Ľ���״̬
	{
		Ordinary,	// ��ͨ״̬
		Suspended,	// ����״̬
		Press		// ����״̬
	};

	struct ButtonStatusColor // ������һ���ṹ�壬�����洢��ť�����ֲ�ͬ����״̬�µĲ�ͬ����䣬������������ɫ��������ɫҲ���ǰ�ť��ǩ��ɫ
	{ 
		COLORREF Ordinary;  // ��ͨ����״̬����ɫ
		COLORREF Suspended; // ��������״̬����ɫ
		COLORREF Press;		// ���½���״̬����ɫ
	};

	struct ButtonSizeLocation // ������һ���ṹ�壬�����洢��ť�Ĵ�С��λ��
	{
		int x;				// ��ť��x����
		int y;				// ��ť��y����
		int width;			// ��ť�Ŀ��
		int height;			// ��ť�ĸ߶�
		int ellipseWidth;   // Բ�ǵĿ��
		int ellipseHeight;  // Բ�ǵĸ߶�
	};

	struct ButtonTagStyle // ������һ���ṹ�壬�����洢��ť��ǩ����ʽ��Ҳ���������ť��ǩ�ı���С������
	{
		int width;	// ��ť��ǩ�ı��Ŀ��
		int height;	// ��ť��ǩ�ı��ĸ߶�
		std::wstring Font; // ��ť��ǩ�ı�����
	};

	class Button : public UI // ������һ��Button(��ť)��,���̳�UI�ӿ���
	{
		public:
			Button(); // Ĭ�Ϲ��캯����������ʼ����ť�ؼ�
			Button(const Button& button); // �������캯����������ʼ����ť�ؼ�
			~Button(); // �����������ͷŰ�ť���е�����Դ

			void SetButtonType(ButtonType buttonType); // �������ð�ť�ķ��
			void SetButtonTag(std::wstring ButtonTag); // �������ð�ť�ı�ǩ
			void SetButtonTagStyle(ButtonTagStyle buttonTagStyle); // �������ð�ť��ǩ��ʽ��Ҳ���������ť��ǩ�ı���С������
			void SetButtonStatusFill(ButtonStatusColor FillColor); // �������ð�ť�����ֵĽ���״̬�µĲ�ͬ�����ɫ
			void SetButtonStatusLine(ButtonStatusColor LineColor); // �������ð�ť�����ֵĽ���״̬�µĲ�ͬ������ɫ
			void SetButtonStatusText(ButtonStatusColor TextColor); // �������ð�ť�����ֵĽ���״̬�µĲ�ͬ������ɫ��Ҳ���ǰ�ť��ǩ����ɫ
			void SetButtonLocation(int x,int y); // �������ð�ťλ��
			void SetButtonSize(int width, int height); // �������ð�ť�Ĵ�С
			void SetButtonSizeLocation(ButtonSizeLocation buttonSizeLocation); // �������ð�ť�Ĵ�С��λ��
			void SetButtonImage(IMAGE* img); // ����ͼƬ��ť�����ֽ���״̬�µĲ�ͬ��ͼƬ
			void SetButtonImagePath(std::wstring* path); // ����ͼƬ��ť�����ֽ���״̬�µĲ�ͬͼƬ��·��

			inline int GetID() override; // ��д�ӿ����еĻ�ȡ�ؼ�ID������������ȡ��ť�ؼ���ID
			void Draw() override; // ��д�ӿ����еĻ��ƿؼ��������������ư�ť�ؼ�
			UIControl::ControlSignal Update(const ExMessage& msg) override; // ��д�ӿ����еĸ��¿ؼ��������������°�ť�ؼ��Ľ���״̬
			bool JudgmentMouseButtonInside(int MouseX, int MouseY); // �ж�����Ƿ��ڰ�ť����
			void CalculationButtonTagCenterCoordinate(); // ���㰴ť��ǩ��������
		private:
			Tool tool; // ���幤�߶����ù��߶���������͸����ͼ��������Ϊ����Щ��ťͼƬ��͸����

			bool FlagID = false; // ��������һ������(bool)������������ǰ�ť�ؼ��Ƿ������ΨһID
			int ID; // ������һ�����α����������洢�ؼ�ΨһID

			int ButtonTagCenterX; // ������һ�����α����������洢��ť��ǩ����x����
			int ButtonTagCenterY; // ������һ�����α����������洢��ť��ǩ����y����
			std::wstring ButtonTag; // ������һ���ַ������������洢��ť��ǩ
			ButtonTagStyle buttonTagStyle; // ������һ���ṹ������������洢��ť��ǩ����ʽ��Ҳ���������ť��ǩ�ı���С������

			ButtonType buttonType; // ������һ��ǿö�ٱ�����������ʾ��ť�ķ��
			ButtonStatus buttonStatus; // ������һ��ǿö�ٱ�����������ʾ��ǰ��ť�Ľ���״̬

			// �����������ṹ����������Ƿֱ������洢��ť�������ֲ�ͬ�Ľ���״̬�µĲ�ͬ����䣬������������ɫ��������ɫҲ���ǰ�ť��ǩ����ɫ
			ButtonStatusColor LineColor;
			ButtonStatusColor FillColor;
			ButtonStatusColor TextColor;

			IMAGE* ButtonStatusImage; // ������һ��ͼƬָ�룬�����洢��ť�����ֲ�ͬ����״̬�µĲ�ͬ�İ�ťͼƬ

			ButtonSizeLocation buttonSizeLocation; // ������һ���ṹ������������洢��ť�Ĵ�С��λ��
	};
}