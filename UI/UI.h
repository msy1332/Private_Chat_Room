#pragma once // 防止头文件重复包含
#include <easyx.h> // 包含easyx图形库头文件

namespace UIControl // 定义了一个UI控件命名空间，为了防止命名冲突
{
	extern int CounterID; // 声明了一个整形变量，用于生成递增的唯一ID的计数器

	enum class ControlSignal // 定义一个强枚举类，用来表示控件触发的信号类型
	{
		Click
	};

	class UI // 定义UI接口类
	{
	public:
		UI();
		virtual ~UI();

		virtual inline int GetID() = 0;
		virtual void Draw() = 0;
		virtual ControlSignal Update(const ExMessage& msg) = 0;
	};
}