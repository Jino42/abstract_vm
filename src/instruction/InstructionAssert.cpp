#include <iostream>
#include "InstructionAssert.hpp"

InstructionAssert::InstructionAssert(IOperand const *operand) :
_type(Assert),
_value(operand)
{
	if (InstructionAssert::_debug)
		std::cout << "InstructionAssert:: Default constructor called." << std::endl;
	return ;
}

InstructionAssert::InstructionAssert(InstructionAssert const &src) :
_type(Assert),
_value(src._value)
{
	if (InstructionAssert::_debug)
		std::cout << "InstructionAssert:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionAssert::~InstructionAssert(void)
{
	if (InstructionAssert::_debug)
		std::cout << "InstructionAssert:: Destructor called." << std::endl;
	return ;
}

InstructionAssert		&InstructionAssert::operator=(InstructionAssert const &rhs)
{
	if (InstructionAssert::_debug)
		std::cout << "InstructionAssert:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionAssert::getType(void) const
{
	return (this->_type);
}

void					InstructionAssert::execute(AvmCore &avm) const
{
	static_cast<void>(avm);
}

const bool		InstructionAssert::_debug = 0;
