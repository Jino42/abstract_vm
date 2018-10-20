#include <iostream>
#include "InstructionMod.hpp"

InstructionMod::InstructionMod(void) :
_type(Mod)
{
	if (InstructionMod::_debug)
		std::cout << "InstructionMod:: Default constructor called." << std::endl;
	return ;
}

InstructionMod::InstructionMod(InstructionMod const &src) :
_type(Mod)
{
	if (InstructionMod::_debug)
		std::cout << "InstructionMod:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionMod::~InstructionMod(void)
{
	if (InstructionMod::_debug)
		std::cout << "InstructionMod:: Destructor called." << std::endl;
	return ;
}

InstructionMod		&InstructionMod::operator=(InstructionMod const &rhs)
{
	if (InstructionMod::_debug)
		std::cout << "InstructionMod:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionMod::getType(void) const
{
	return (this->_type);
}

void					InstructionMod::execute(AvmCore &avm) const
{
	static_cast<void>(avm);
}

const bool		InstructionMod::_debug = 0;
