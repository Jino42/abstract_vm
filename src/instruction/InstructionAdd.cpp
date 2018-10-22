#include <iostream>
#include "InstructionAdd.hpp"
#include "AvmCore.hpp"
#include "InstructionException.hpp"

InstructionAdd::InstructionAdd(void) :
AInstruction("Add", Add)
{
	if (InstructionAdd::_debug)
		std::cout << "InstructionAdd:: Default constructor called." << std::endl;
	return ;
}

InstructionAdd::~InstructionAdd(void)
{
	if (InstructionAdd::_debug)
		std::cout << "InstructionAdd:: Destructor called." << std::endl;
	return ;
}

void					InstructionAdd::execute(AvmCore &avm) const
{
	if (avm.getStack().size() < 2)
	{
		if (!avm.getStack().size())
			throw(InstructionException::StackTooSmall("Trying Add with a empty stack"));
		throw(InstructionException::StackTooSmall("Trying Add with a too small stack"));
	}

	IOperand const *v1 = avm.getStack().top();
	avm.getStack().pop();
	IOperand const *v2 = avm.getStack().top();
	avm.getStack().pop();

	avm.getStack().push(*v2 + *v1);
	delete v1;
	delete v2;
}

const bool		InstructionAdd::_debug = 0;
