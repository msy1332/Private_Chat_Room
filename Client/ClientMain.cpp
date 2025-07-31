#include <iostream> // ������׼�������ͷ�ļ�
#include <windows.h> // ����windowsϵͳ��APIͷ�ļ�
#include <vector> // ����vector������ͷ�ļ�
#include "../UI/UI.h" // ����UI�ӿ����ͷ�ļ�
#include "../UI/Button/Button.h" // ������ť��ͷ�ļ�
#include "../UI/TextBox/TextBox.h" // �����ı������ͷ�ļ�
#include "../Tool/Tool.h" // ��������ͷ�ļ�
using namespace std; // ʹ��std�����ռ�
using namespace UIControl; // ʹ��UIControl�����ռ�
int main()
{
	// ��ʼ������
	initgraph(800, 600, EX_SHOWCONSOLE); // ��������
	setbkcolor(RGB(240, 240, 240)); // ���ñ�����ɫ
	cleardevice(); // �����ͼ���ڣ����ñ�����ɫ�����������
	setbkmode(TRANSPARENT); // ���ñ���ģʽΪ͸��ģʽ���������Ƴ������ֵı�������͸����

	/*
		// ��ʼ��UI
		Button button;
		Button button1;
		TextBox textbox1;
		vector<UI*> ui = { &button,&button1, &textbox1};

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
	*/

	// ��ʼ��UI
	Button button1;

	Button button2;
	button2.SetButtonType(ButtonType::Without_borders_Fill_Button);
	button2.SetButtonLocation(220, 0);

	Button button3;
	button3.SetButtonType(ButtonType::With_borders_Fill_Rounded_Button);
	// ���ð�ť�Ĵ�С��λ��
	ButtonSizeLocation buttonSizeLocation1;
	buttonSizeLocation1.x = 0;
	buttonSizeLocation1.y = 70;
	buttonSizeLocation1.width = 200;
	buttonSizeLocation1.height = 50;
	buttonSizeLocation1.ellipseWidth = 15;
	buttonSizeLocation1.ellipseHeight = 15;
	button3.SetButtonSizeLocation(buttonSizeLocation1);

	Button button4;
	button4.SetButtonType(ButtonType::Without_borders_Fill_Rounded_Button);
	// ���ð�ť�Ĵ�С��λ��
	ButtonSizeLocation buttonSizeLocation2;
	buttonSizeLocation2.x = 220;
	buttonSizeLocation2.y = 70;
	buttonSizeLocation2.width = 200;
	buttonSizeLocation2.height = 50;
	buttonSizeLocation2.ellipseWidth = 15;
	buttonSizeLocation2.ellipseHeight = 15;
	button4.SetButtonSizeLocation(buttonSizeLocation2);

	Button button5;
	button5.SetButtonType(ButtonType::Picture_Button);
	button5.SetButtonLocation(0, 140);
	wstring ButtonStatusImagePath[3];
	ButtonStatusImagePath[0] = L"E:\\C++\\VS_Project\\Private_Chat_Room\\Private_Chat_Room\\Res\\Image\\Button1.png";
	ButtonStatusImagePath[1] = L"E:\\C++\\VS_Project\\Private_Chat_Room\\Private_Chat_Room\\Res\\Image\\Button2.png";
	ButtonStatusImagePath[2] = L"E:\\C++\\VS_Project\\Private_Chat_Room\\Private_Chat_Room\\Res\\Image\\Button3.png";
	button5.SetButtonImagePath(ButtonStatusImagePath);

	vector<UI*> ui{ &button1,&button2,&button3,&button4,&button5 };

	bool Running = true; // ������һ��bool������������ǳ��������״̬
	ExMessage msg; // ����һ����Ϣ�ṹ�壬�����洢��ȡ����Ϣ

	BeginBatchDraw(); // ����˫�����ͼ
	while (Running)
	{
		while (peekmessage(&msg, EX_MOUSE)) // ��ȡ��Ϣ
		{
			//button.Updata(msg); // ���°�ť�Ľ���״̬
			//if(button1.Updata(msg) == UISignal::Click) // ���°�ť�Ľ���״̬
			//{
			//	Running = false;
			//}
			for (auto it : ui)
			{
				if (it->Updata(msg) == ControlSignal::Click)
				{
					switch (it->GetID())
					{
					case 0:
						cout << "Button0 Click" << endl;
						break;
					case 1:
						cout << "Button1 Click" << endl;
						break;
					case 2:
						cout << "Button2 Click" << endl;
						break;
					case 3:
						cout << "Button3 Click" << endl;
						break;
					case 4:
						cout << "Button4 Click" << endl;
						break;
					case 5:
						cout << "Button5 Click" << endl;
						break;
					}
				}
			}
			//button1.Updata(msg);
			//button2.Updata(msg);
			/*button3.Updata(msg);*/
		}

		cleardevice(); // �����ͼ���ڣ����ñ�����ɫ�����������
		////button.Draw(); // ���ư�ť
		////button1.Draw(); // ���ư�ť
		for (auto it : ui)
			it->Draw();
		//button1.Draw();
		//button2.Draw();
		/*button3.Draw();*/
		FlushBatchDraw(); // ˢ�»�ͼ������
	}
	EndBatchDraw(); // ����˫�����ͼ
	return 0;
}
