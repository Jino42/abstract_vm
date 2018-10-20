#include <iostream>
#include "InstructionPop.hpp"

InstructionPop::InstructionPop(void) :
_type(Pop)
{
	if (InstructionPop::_debug)
		std::cout << "InstructionPop:: Default constructor called." << std::endl;
	return ;
}

InstructionPop::InstructionPop(InstructionPop const &src) :
_type(Pop)
{
	if (InstructionPop::_debug)
		std::cout << "InstructionPop:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionPop::~InstructionPop(void)
{
	if (InstructionPop::_debug)
		std::cout << "InstructionPop:: Destructor called." << std::endl;
	return ;
}

InstructionPop		&InstructionPop::operator=(InstructionPop const &rhs)
{
	if (InstructionPop::_debug)
		std::cout << "InstructionPop:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionPop::getType(void) const
{
	return (this->_type);
}

void					InstructionPop::execute(AvmCore &avm) const
{
	static_cast<void>(avm);
}

const bool		InstructionPop::_debug = 0;
