#pragma once // 防止头文件重复包含
#include <iostream> // 包含标准输入输出头文件
#include <easyx.h> // 包含easyx图形库头文件

class Tool
{
	public:
		Tool();
		~Tool();
		void Transparent_texture(int x, int y, IMAGE* img); // 透明贴图函数
	private:
	protected:
};