#pragma once // ��ֹͷ�ļ��ظ�����
#include <easyx.h> // ����easyxͼ�ο�ͷ�ļ�

enum class UISignal // ����һ���źŵ�Ȩ������
{
	Click
};

class UI // ����һ��UI�Ľӿ���
{
	public:
		UI();
		virtual ~UI();
		
		virtual void Draw() = 0;
		virtual UISignal Updata(ExMessage msg) = 0;
};