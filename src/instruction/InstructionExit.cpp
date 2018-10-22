#include <iostream>
#include "InstructionExit.hpp"
#include "AvmCore.hpp"
#include "InstructionException.hpp"

InstructionExit::InstructionExit(void) :
AInstruction("Exit", Exit)
{
	if (InstructionExit::_debug)
		std::cout << "InstructionExit:: Default constructor called." << std::endl;
	return ;
}

InstructionExit::~InstructionExit(void)
{
	if (InstructionExit::_debug)
		std::cout << "InstructionExit:: Destructor called." << std::endl;
	return ;
}

void					InstructionExit::execute(AvmCore &avm) const
{
	avm.setExit(true);
}

const bool		InstructionExit::_debug = 0;
