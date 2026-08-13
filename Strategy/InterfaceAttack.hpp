#pragma once

#include <iostream>


class InterfaceAttack
{
	public:
		InterfaceAttack() = default;
		virtual ~InterfaceAttack() = default;
		InterfaceAttack(const InterfaceAttack& other) = delete;
		InterfaceAttack(InterfaceAttack&&) = default;
		InterfaceAttack& operator=(const InterfaceAttack& other) = delete;
		InterfaceAttack& operator=(InterfaceAttack&&) = default;
		virtual void chooseAttack() = 0;
};
