#pragma once // ��ֹͷ�ļ��ظ�����
#include <iostream> // ������׼�������ͷ�ļ�
#include <easyx.h> // ����easyxͼ�ο�
#include <string> // �����ַ���(string)ͷ�ļ�
#include <windows.h> // ����windows APIͷ�ļ�
#include "../UI.h" // ����UI�ӿ���ͷ�ļ�
using namespace std; // ʹ��std�����ռ�

namespace UIControl // ������һ��UI�ؼ������ռ䣬Ϊ�˷�ֹ������ͻ
{
	enum class TextBoxType // ������һ��ǿö���࣬������ʾ��ͬ�����ı����������
	{
		With_borders_Fill_TextBox,				// ���߿���ı������
		Without_borders_Fill_TextBox,			// �����߿���ı������
		With_borders_Fill_Rounded_TextBox,		// ���߿��Բ���ı������
		Without_borders_Fill_Rounded_TextBox,	// �����߿��Բ���ı������
	};

	enum class TextBoxStatus // ������һ��ǿö���࣬������ʾ�ı����������ֲ�ͬ�Ľ���״̬
	{
		Ordinary,	// ��ͨ״̬
		Suspended,	// ����״̬
		Input		// ����״̬
	};

	enum class TextBoxMode // ������һ��ǿö���࣬������ʾ�ı�������ģʽ
	{
		Single_line,	// ����ģʽ
		Multiple_lines	// ����ģʽ
	};

	struct TextBoxTexiStyle // ������һ���ṹ�壬�����洢�ı�������ı�����ʽ
	{
		int width; // �ı��Ŀ��
		int height;// �ı��ĸ߶�
		std::wstring Font; // �ı����������ʽ
		bool AlignMode; // �ı��Ķ���ģʽ
	};

	struct TextBoxStatusColor // ������һ���ṹ������������洢�ı����������ֲ�ͬ�Ľ���״̬�µ���䣬�������ı���ɫ
	{ 
		COLORREF Ordinary;	// ��ͨ����״̬�µ���ɫ
		COLORREF Suspended;	// ��������״̬�µ���ɫ
		COLORREF Input;		// ���뽻��״̬�µ���ɫ
	};

	struct TextSizeLocation // ������һ���ṹ�壬�����洢�ı�������С��λ��
	{
		int x;		// �ı�������x����
		int y;		// �ı�������y����
		int width;	// �ı������Ŀ��
		int line;   // �ı���������
	};

	class TextBox : public UI // ������һ���ı�������࣬���̳�UI�ӿ���
	{
		public:
			TextBox();
			TextBox(const TextBox& textBox);
			~TextBox();

			int GetID() override; // ��д�˽ӿ����еĻ�ȡ�ؼ�ID������������ȡ�ı������ؼ�ID
			void Draw() override; // ��д�˽ӿ���Ļ��ƿؼ����������������ı������ؼ�����
			UIControl::ControlSignal Update(const ExMessage& msg) override; // ��д�˽ӿ����еĸ��¿ؼ�״̬���������������ı������ؼ�״̬����
		private:
			int ID; // �������α����������洢�ı������ؼ�ID

			TextBoxType textBoxType; // ������һ��ǿö�ٱ�����������ʾ�ı��������
			TextBoxStatus textBoxStatus; // ������һ��ǿö�ٱ�����������ʾ��ǰ�ı�����򽻻�״̬
			TextBoxMode textBoxMode; // ������һ��ǿö�ٱ�����������ʾ�ı������ģʽ

			TextBoxTexiStyle textBoxTexiStyle; // ������һ���ṹ������������洢�ı�������ı�����ʽ
			
			// �����������ṹ��������ֱ��������洢�ı�������������ֲ�ͬ�Ľ���״̬�µ���䣬�������ı���ɫ
			TextBoxStatusColor FillColor;
			TextBoxStatusColor LineColor;
			TextBoxStatusColor TextColor;

			TextSizeLocation textSizeLocation; //������һ���ṹ������������洢�ı�������С��λ��
	};
}
