#include "Tool.h"

Tool::Tool()
{

}

Tool::~Tool()
{

}

void Tool::Transparent_texture(int x, int y, IMAGE* img)
{
	DWORD* WindowsBuffer = GetImageBuffer(); // ��ȡ���ڵĻ�����ָ��
	DWORD* IMAGEBuffer = GetImageBuffer(img); // ��ȡͼƬ�Ļ�����ָ��

	int WindowsWidth = getwidth(); // ��ȡ���ڵĿ��
	int WindowsHeight = getheight(); // ��ȡ���ڵĸ߶�

	int ImageWidth = img->getwidth(); // ��ȡͼƬ�Ŀ��
	int ImageHeight = img->getheight(); // ��ȡͼƬ�ĸ߶�

	int Actual_ImageWidth = ImageWidth; // ͼƬ��ʵ�ʿ��
	int Actual_ImageHeight = ImageHeight; // ͼƬʵ�ʸ߶�

	if (x + ImageWidth > WindowsWidth) // �ж�ͼƬ�Ƿ񳬳����ڵ��ұ߽�
	{
		Actual_ImageWidth = WindowsWidth - x; // ����ͼƬ��ʵ�ʿ��
	}

	if (y + ImageHeight > WindowsHeight) // �ж�ͼƬ�Ƿ񳬳����ڵ��±߽�
	{
		Actual_ImageHeight = WindowsHeight - y; // ����ͼƬ��ʵ�ʿ��
	}

	if (x < 0) // �ж�ͼƬ�Ƿ񳬳����ڵ���߽�
	{
		IMAGEBuffer += -x;
		x = 0;
	}

	if (y < 0) // �ж�ͼƬ�Ƿ񳬳����ڵ��ϱ߽�
	{
		IMAGEBuffer += -y * ImageWidth;
		y = 0;
	}

	for (int i = 0; i < Actual_ImageHeight; i++)
	{
		for (int j = 0; j < Actual_ImageWidth; j++)
		{
			UCHAR A = IMAGEBuffer[j + (i * ImageWidth)] >> 24;
			if (A > 200)
			{
				WindowsBuffer[(j + x) + ((i + y) * WindowsWidth)] = IMAGEBuffer[j + (i * ImageWidth)];
			}
		}
	}
}