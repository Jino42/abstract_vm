#include <iostream>
#include "InstructionPop.hpp"
#include "AvmCore.hpp"
#include "InstructionException.hpp"

InstructionPop::InstructionPop(void) :
AInstruction("Pop", Pop)
{
	if (InstructionPop::_debug)
		std::cout << "InstructionPop:: Default constructor called." << std::endl;
	return ;
}

InstructionPop::~InstructionPop(void)
{
	if (InstructionPop::_debug)
		std::cout << "InstructionPop:: Destructor called." << std::endl;
	return ;
}

void					InstructionPop::execute(AvmCore &avm) const
{
	if (!avm.getStack().size())
		throw(InstructionException::StackTooSmall("Trying Pop a empty stack"));

	IOperand const *v1 = avm.getStack().top();
	avm.getStack().pop();

	delete v1;
}

const bool		InstructionPop::_debug = 0;
