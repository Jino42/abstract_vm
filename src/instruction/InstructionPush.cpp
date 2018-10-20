#include <iostream>
#include "InstructionPush.hpp"

InstructionPush::InstructionPush(IOperand const *operand) :
_type(Push),
_value(operand)
{
	if (InstructionPush::_debug)
		std::cout << "InstructionPush:: Default constructor called." << std::endl;
	return ;
}

InstructionPush::InstructionPush(InstructionPush const &src) :
_type(Push),
_value(src._value)
{
	if (InstructionPush::_debug)
		std::cout << "InstructionPush:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionPush::~InstructionPush(void)
{
	if (InstructionPush::_debug)
		std::cout << "InstructionPush:: Destructor called." << std::endl;
	return ;
}

InstructionPush		&InstructionPush::operator=(InstructionPush const &rhs)
{
	if (InstructionPush::_debug)
		std::cout << "InstructionPush:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionPush::getType(void) const
{
	return (this->_type);
}

void					InstructionPush::execute(AvmCore &avm) const
{
	static_cast<void>(avm);
}

const bool		InstructionPush::_debug = 0;
