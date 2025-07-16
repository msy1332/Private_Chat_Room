#pragma once // ��ֹͷ�ļ��ظ�����
#include <iostream> // ������׼�������ͷ�ļ�
#include <easyx.h> // ����easyxͼ�ο�
#include <string> // �����ַ���(string)ͷ�ļ�
#include "../UI.h" // ����UI�ӿ����ͷ�ļ�

enum class TextBoxType // ������һ��ǿö���࣬������ʾ��ͬ�����ı����������
{
	Have_border_fill,            // ���߿������ı������
	Borderless_fill,             // �����߿������ı������
	Have_border_fill_rounded,    // ���߿�����Բ���ı������
	Borderless_fill_rounded,     // �����߿�����Բ���ı������
};

enum class TextBoxStatus // ����һ��ǿö���࣬������ʾ��ǰ�ı������Ľ���״̬
{
	Ordinary,	// ��ͨ״̬
	Suspended,	// ����״̬
	Input		// ����״̬
};

enum class TextBoxMode // ������һ��ǿö���࣬������ʾ��ǰ�ı�������ģʽ
{
	Single_line, // ����ģʽ
	Multiple_lines // ����ģʽ
};

struct TextBoxStatusColor // ����һ���ṹ�壬������ʾ�ı��������������ֽ���״̬�µ���ɫ����
{
	COLORREF Ordinary;	// ��ͨ״̬�µ���ɫ
	COLORREF Suspended;	// ����״̬�µ���ɫ
	COLORREF Press;		// ����״̬�µ���ɫ
};

struct TextStyle // ����һ���ṹ�壬�����洢�ı��������ı���С
{
	int TextWidth;  // �ı��������ı��Ŀ��
	int TextHeigth; // �ı��������ı��ĸ߶�
};

struct TextBoxSizeLocation // ����һ���ṹ�壬�����洢�ı������Ĵ�С��λ�ú�Բ�ǵĳߴ�
{
	int x; // �ı�������x����
	int y; // �ı�������y����
	int width; // �ı������Ŀ��
	int ellipsewidth;	// �ı������Բ�ǵĿ��
	int ellipseheight;	// �ı������Բ�ǵĸ߶�
};

class TextBox : public UI // ������һ���ı�������UI�࣬���̳����UI�Ľӿ���
{
	public:
	private:
	protected:
};