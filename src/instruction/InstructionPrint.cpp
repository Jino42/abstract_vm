#include <iostream>
#include "InstructionPrint.hpp"

InstructionPrint::InstructionPrint(void) :
_type(Print)
{
	if (InstructionPrint::_debug)
		std::cout << "InstructionPrint:: Default constructor called." << std::endl;
	return ;
}

InstructionPrint::InstructionPrint(InstructionPrint const &src) :
_type(Print)
{
	if (InstructionPrint::_debug)
		std::cout << "InstructionPrint:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionPrint::~InstructionPrint(void)
{
	if (InstructionPrint::_debug)
		std::cout << "InstructionPrint:: Destructor called." << std::endl;
	return ;
}

InstructionPrint		&InstructionPrint::operator=(InstructionPrint const &rhs)
{
	if (InstructionPrint::_debug)
		std::cout << "InstructionPrint:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionPrint::getType(void) const
{
	return (this->_type);
}

void					InstructionPrint::execute(AvmCore &avm) const
{
	static_cast<void>(avm);
}

const bool		InstructionPrint::_debug = 0;
