#include <iostream>
#include "InstructionAdd.hpp"

InstructionAdd::InstructionAdd(void) :
_type(Add)
{
	if (InstructionAdd::_debug)
		std::cout << "InstructionAdd:: Default constructor called." << std::endl;
	return ;
}

InstructionAdd::InstructionAdd(InstructionAdd const &src) :
_type(Add)
{
	if (InstructionAdd::_debug)
		std::cout << "InstructionAdd:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionAdd::~InstructionAdd(void)
{
	if (InstructionAdd::_debug)
		std::cout << "InstructionAdd:: Destructor called." << std::endl;
	return ;
}

InstructionAdd		&InstructionAdd::operator=(InstructionAdd const &rhs)
{
	if (InstructionAdd::_debug)
		std::cout << "InstructionAdd:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionAdd::getType(void) const
{
	return (this->_type);
}

void					InstructionAdd::execute(AvmCore &avm) const
{
	static_cast<void>(avm);
}

const bool		InstructionAdd::_debug = 0;
