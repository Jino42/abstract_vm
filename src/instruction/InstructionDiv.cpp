#include <iostream>
#include "InstructionDiv.hpp"

InstructionDiv::InstructionDiv(void) :
_type(Div)
{
	if (InstructionDiv::_debug)
		std::cout << "InstructionDiv:: Default constructor called." << std::endl;
	return ;
}

InstructionDiv::InstructionDiv(InstructionDiv const &src) :
_type(Div)
{
	if (InstructionDiv::_debug)
		std::cout << "InstructionDiv:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionDiv::~InstructionDiv(void)
{
	if (InstructionDiv::_debug)
		std::cout << "InstructionDiv:: Destructor called." << std::endl;
	return ;
}

InstructionDiv		&InstructionDiv::operator=(InstructionDiv const &rhs)
{
	if (InstructionDiv::_debug)
		std::cout << "InstructionDiv:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionDiv::getType(void) const
{
	return (this->_type);
}

void					InstructionDiv::execute(AvmCore &avm) const
{
	static_cast<void>(avm);
}

const bool		InstructionDiv::_debug = 0;
