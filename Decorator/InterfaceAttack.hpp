#pragma once

#include <iostream>


class InterfaceAttack
{
	public:
		InterfaceAttack() = default;
		InterfaceAttack(const InterfaceAttack& other) = delete;
		InterfaceAttack(InterfaceAttack&&) noexcept = default;
		InterfaceAttack& operator=(const InterfaceAttack& other) = delete;
		InterfaceAttack& operator=(InterfaceAttack&&) noexcept = default;
		virtual ~InterfaceAttack() = default;
		virtual void chooseAttack() = 0;
};
