#include <iostream>
#include "InstructionExit.hpp"
#include "AvmCore.hpp"

InstructionExit::InstructionExit(void) :
_type(Exit)
{
	if (InstructionExit::_debug)
		std::cout << "InstructionExit:: Default constructor called." << std::endl;
	return ;
}

InstructionExit::InstructionExit(InstructionExit const &src) :
_type(Exit)
{
	if (InstructionExit::_debug)
		std::cout << "InstructionExit:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionExit::~InstructionExit(void)
{
	if (InstructionExit::_debug)
		std::cout << "InstructionExit:: Destructor called." << std::endl;
	return ;
}

InstructionExit		&InstructionExit::operator=(InstructionExit const &rhs)
{
	if (InstructionExit::_debug)
		std::cout << "InstructionExit:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionExit::getType(void) const
{
	return (this->_type);
}

void					InstructionExit::execute(AvmCore &avm) const
{
	static_cast<void>(avm);
}

const bool		InstructionExit::_debug = 0;
