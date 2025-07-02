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
	vector<UI*> ui = { &button,&button1 };

	ButtonSizeLocation buttonSizeLocation;
	buttonSizeLocation.x = 778;
	buttonSizeLocation.y = 2;
	buttonSizeLocation.width = 20;
	buttonSizeLocation.height = 20;
	button1.SetButtonSizeLocation(buttonSizeLocation);

	button1.SetButtonType(ButtonType::Borderless_fill);
	button1.SetText(L"��");

	ButtonStatusColor Fill;
	Fill.Ordinary = RGB(240, 240, 240);
	Fill.Suspended = RGB(232, 17, 35);
	Fill.Press = RGB(241, 112, 122);
	button1.SetFillColor(Fill);

	ButtonStatusColor Text;
	Text.Ordinary = RGB(5, 7, 8);
	Text.Suspended = RGB(255, 255, 255);
	Text.Press = RGB(255, 255, 255);
	button1.SetTextColor(Text);


	bool Running = true; // ������һ��bool������������ǳ��������״̬
	ExMessage msg; // ����һ����Ϣ�ṹ�壬�����洢��ȡ����Ϣ

	BeginBatchDraw(); // ����˫�����ͼ
	while (Running)
	{
		while (peekmessage(&msg, EX_MOUSE)) // ��ȡ��Ϣ
		{
			button.Updata(msg); // ���°�ť�Ľ���״̬
			if(button1.Updata(msg) == UISignal::Click) // ���°�ť�Ľ���״̬
			{
				Running = false;
			}
		}

		cleardevice(); // �����ͼ���ڣ����ñ�����ɫ�����������
		//button.Draw(); // ���ư�ť
		//button1.Draw(); // ���ư�ť
		for (auto it : ui)
			it->Draw();
		FlushBatchDraw(); // ˢ�»�ͼ������
	}
	EndBatchDraw(); // ����˫�����ͼ
	return 0;
}