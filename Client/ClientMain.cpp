#include <iostream> // ������׼�������ͷ�ļ�
#include <windows.h> // ����windowsϵͳ��APIͷ�ļ�
#include <vector> // ����vector������ͷ�ļ�
#include "../UI/UI.h" // ����UI�ӿ����ͷ�ļ�
#include "../UI/Button/Button.h" // ������ť��ͷ�ļ�
using namespace std;
int main()
{
	// ��ʼ������
	initgraph(800, 600, EX_SHOWCONSOLE); // ��������
	setbkcolor(RGB(240, 240, 240)); // ���ñ�����ɫ
	cleardevice(); // �����ͼ���ڣ����ñ�����ɫ�����������
	setbkmode(TRANSPARENT); // ���ñ���ģʽΪ͸��ģʽ���������Ƴ������ֵı�������͸����

	// ��ʼ��UI
	Button button;
	Button button1;
	button1.SetButtonX(210);

	bool Running = true; // ������һ��bool������������ǳ��������״̬
	ExMessage msg; // ����һ����Ϣ�ṹ�壬�����洢��ȡ����Ϣ

	BeginBatchDraw(); // ����˫�����ͼ
	while (Running)
	{
		while (peekmessage(&msg, EX_MOUSE)) // ��ȡ��Ϣ
		{
			button.Updata(msg); // ���°�ť�Ľ���״̬
			button1.Updata(msg); // ���°�ť�Ľ���״̬
		}

		cleardevice(); // �����ͼ���ڣ����ñ�����ɫ�����������
		button.Draw(); // ���ư�ť
		button1.Draw(); // ���ư�ť
		FlushBatchDraw(); // ˢ�»�ͼ������
	}
	EndBatchDraw(); // ����˫�����ͼ
	return 0;
}