#include "Tool.h"

Tool::Tool()
{

}

Tool::~Tool()
{

}

void Tool::Transparent_texture(int x, int y, IMAGE* img)
{
	DWORD* WindowsBuffer = GetImageBuffer(); // 获取窗口的缓冲区指针
	DWORD* IMAGEBuffer = GetImageBuffer(img); // 获取图片的缓冲区指针

	int WindowsWidth = getwidth(); // 获取窗口的宽度
	int WindowsHeight = getheight(); // 获取窗口的高度

	int ImageWidth = img->getwidth(); // 获取图片的宽度
	int ImageHeight = img->getheight(); // 获取图片的高度

	int Actual_ImageWidth = ImageWidth; // 图片的实际宽度
	int Actual_ImageHeight = ImageHeight; // 图片实际高度

	if (x + ImageWidth > WindowsWidth) // 判断图片是否超出窗口的右边界
	{
		Actual_ImageWidth = WindowsWidth - x; // 更新图片的实际宽度
	}

	if (y + ImageHeight > WindowsHeight) // 判断图片是否超出窗口的下边界
	{
		Actual_ImageHeight = WindowsHeight - y; // 更新图片的实际宽度
	}

	if (x < 0) // 判断图片是否超出窗口的左边界
	{
		IMAGEBuffer += -x;
		x = 0;
	}

	if (y < 0) // 判断图片是否超出窗口的上边界
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