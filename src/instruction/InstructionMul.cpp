#include <iostream>
#include "InstructionMul.hpp"

InstructionMul::InstructionMul(void) :
_type(Mul)
{
	if (InstructionMul::_debug)
		std::cout << "InstructionMul:: Default constructor called." << std::endl;
	return ;
}

InstructionMul::InstructionMul(InstructionMul const &src) :
_type(Mul)
{
	if (InstructionMul::_debug)
		std::cout << "InstructionMul:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionMul::~InstructionMul(void)
{
	if (InstructionMul::_debug)
		std::cout << "InstructionMul:: Destructor called." << std::endl;
	return ;
}

InstructionMul		&InstructionMul::operator=(InstructionMul const &rhs)
{
	if (InstructionMul::_debug)
		std::cout << "InstructionMul:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionMul::getType(void) const
{
	return (this->_type);
}

void					InstructionMul::execute(AvmCore &avm) const
{
	static_cast<void>(avm);
}

const bool		InstructionMul::_debug = 0;
