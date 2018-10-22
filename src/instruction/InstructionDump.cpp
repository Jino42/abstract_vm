#include <iostream>
#include "InstructionDump.hpp"
#include "AvmCore.hpp"
#include "InstructionException.hpp"

InstructionDump::InstructionDump(void) :
AInstruction("Dump", Dump)
{
	if (InstructionDump::_debug)
		std::cout << "InstructionDump:: Default constructor called." << std::endl;
	return ;
}

InstructionDump::~InstructionDump(void)
{
	if (InstructionDump::_debug)
		std::cout << "InstructionDump:: Destructor called." << std::endl;
	return ;
}

void					InstructionDump::execute(AvmCore &avm) const
{
	avm.printStack();
}

const bool		InstructionDump::_debug = 0;
