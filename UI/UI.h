#pragma once // ��ֹͷ�ļ��ظ�����
#include <easyx.h> // ����easyxͼ�ο�ͷ�ļ�

namespace UIControl // ������һ��UI�ؼ������ռ䣬Ϊ�˷�ֹ������ͻ
{
	extern int CounterID; // ������һ�����α������������ɵ�����ΨһID�ļ�����

	enum class ControlSignal // ����һ��ǿö���࣬������ʾ�ؼ��������ź�����
	{
		Click
	};

	class UI // ����UI�ӿ���
	{
	public:
		UI();
		virtual ~UI();

		virtual inline int GetID() = 0;
		virtual void Draw() = 0;
		virtual ControlSignal Update(const ExMessage& msg) = 0;
	};
}