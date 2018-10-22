#include <iostream>
#include "InstructionSub.hpp"
#include "AvmCore.hpp"
#include "InstructionException.hpp"

InstructionSub::InstructionSub(void) :
AInstruction("Sub", Sub)
{
	if (InstructionSub::_debug)
		std::cout << "InstructionSub:: Default constructor called." << std::endl;
	return ;
}

InstructionSub::~InstructionSub(void)
{
	if (InstructionSub::_debug)
		std::cout << "InstructionSub:: Destructor called." << std::endl;
	return ;
}

void					InstructionSub::execute(AvmCore &avm) const
{
	if (avm.getStack().size() < 2)
	{
		if (!avm.getStack().size())
			throw(InstructionException::StackTooSmall("Trying Sub with a empty stack"));
		throw(InstructionException::StackTooSmall("Trying Sub with a too small stack"));
	}

	IOperand const *v1 = avm.getStack().top();
	avm.getStack().pop();
	IOperand const *v2 = avm.getStack().top();
	avm.getStack().pop();

	avm.getStack().push(*v2 - *v1);
	delete v1;
	delete v2;
}

const bool		InstructionSub::_debug = 0;
