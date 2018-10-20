#include <iostream>
#include "InstructionDump.hpp"
#include "AvmCore.hpp"

InstructionDump::InstructionDump(void) :
_type(Dump)
{
	if (InstructionDump::_debug)
		std::cout << "InstructionDump:: Default constructor called." << std::endl;
	return ;
}

InstructionDump::InstructionDump(InstructionDump const &src) :
_type(Dump)
{
	if (InstructionDump::_debug)
		std::cout << "InstructionDump:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionDump::~InstructionDump(void)
{
	if (InstructionDump::_debug)
		std::cout << "InstructionDump:: Destructor called." << std::endl;
	return ;
}

InstructionDump		&InstructionDump::operator=(InstructionDump const &rhs)
{
	if (InstructionDump::_debug)
		std::cout << "InstructionDump:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionDump::getType(void) const
{
	return (this->_type);
}

void					InstructionDump::execute(AvmCore &avm) const
{
	static_cast<void>(avm);
}

const bool		InstructionDump::_debug = 0;
