#pragma once // 防止头文件重复包含
#include <easyx.h> // 包含easyx图形库头文件

enum class UISignal // 定义一个信号的权举类型
{
	Click
};

class UI // 定义一个UI的接口类
{
	public:
		UI();
		virtual ~UI();
		
		virtual void Draw() = 0;
		virtual UISignal Updata(ExMessage msg) = 0;
};