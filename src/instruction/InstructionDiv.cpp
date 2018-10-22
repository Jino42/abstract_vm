#include <iostream>
#include "InstructionDiv.hpp"
#include "AvmCore.hpp"
#include "InstructionException.hpp"

InstructionDiv::InstructionDiv(void) :
AInstruction("Div", Div)
{
	if (InstructionDiv::_debug)
		std::cout << "InstructionDiv:: Default constructor called." << std::endl;
	return ;
}

InstructionDiv::~InstructionDiv(void)
{
	if (InstructionDiv::_debug)
		std::cout << "InstructionDiv:: Destructor called." << std::endl;
	return ;
}

void					InstructionDiv::execute(AvmCore &avm) const
{
	if (avm.getStack().size() < 2)
	{
		if (!avm.getStack().size())
			throw(InstructionException::StackTooSmall("Trying Div with a empty stack"));
		throw(InstructionException::StackTooSmall("Trying Div with a too small stack"));
	}

	IOperand const *v1 = avm.getStack().top();
	avm.getStack().pop();
	IOperand const *v2 = avm.getStack().top();
	avm.getStack().pop();

	if (std::stod(v1->toString()) == 0.0)
		throw(InstructionException::DivByZero());
	avm.getStack().push(*v2 / *v1);
	delete v1;
	delete v2;
}

const bool		InstructionDiv::_debug = 0;
