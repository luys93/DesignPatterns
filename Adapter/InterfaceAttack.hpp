#pragma once

#include <iostream>


class InterfaceAttack
{
	public:
		virtual ~InterfaceAttack() = default;
		virtual void chooseAttack() = 0;
};
