#include <iostream>
#include "InstructionSub.hpp"

InstructionSub::InstructionSub(void) :
_type(Sub)
{
	if (InstructionSub::_debug)
		std::cout << "InstructionSub:: Default constructor called." << std::endl;
	return ;
}

InstructionSub::InstructionSub(InstructionSub const &src) :
_type(Sub)
{
	if (InstructionSub::_debug)
		std::cout << "InstructionSub:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionSub::~InstructionSub(void)
{
	if (InstructionSub::_debug)
		std::cout << "InstructionSub:: Destructor called." << std::endl;
	return ;
}

InstructionSub		&InstructionSub::operator=(InstructionSub const &rhs)
{
	if (InstructionSub::_debug)
		std::cout << "InstructionSub:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionSub::getType(void) const
{
	return (this->_type);
}

void					InstructionSub::execute(AvmCore &avm) const
{
	static_cast<void>(avm);
}

const bool		InstructionSub::_debug = 0;
