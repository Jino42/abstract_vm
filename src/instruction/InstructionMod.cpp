#include <iostream>
#include "InstructionMod.hpp"
#include "AvmCore.hpp"
#include "InstructionException.hpp"

InstructionMod::InstructionMod(void) :
AInstruction("Mod", Mod)
{
	if (InstructionMod::_debug)
		std::cout << "InstructionMod:: Default constructor called." << std::endl;
	return ;
}

InstructionMod::~InstructionMod(void)
{
	if (InstructionMod::_debug)
		std::cout << "InstructionMod:: Destructor called." << std::endl;
	return ;
}

void					InstructionMod::execute(AvmCore &avm) const
{
	if (avm.getStack().size() < 2)
	{
		if (!avm.getStack().size())
			throw(InstructionException::StackTooSmall("Trying Mod with a empty stack"));
		throw(InstructionException::StackTooSmall("Trying Mod with a too small stack"));
	}

	IOperand const *v1 = avm.getStack().top();
	avm.getStack().pop();
	IOperand const *v2 = avm.getStack().top();
	avm.getStack().pop();

	avm.getStack().push(*v2 % *v1);
	delete v1;
	delete v2;
}

const bool		InstructionMod::_debug = 0;
