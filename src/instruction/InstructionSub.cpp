#include <iostream>
#include "InstructionSub.hpp"
#include "AvmCore.hpp"

InstructionSub::InstructionSub(void) :
_type(Sub)
{
	if (InstructionSub::_debug)
		std::cout << "InstructionSub:: Default constructor called." << std::endl;
	return ;
}

InstructionSub::InstructionSub(InstructionSub const &src) :
_type(Sub)
{
	if (InstructionSub::_debug)
		std::cout << "InstructionSub:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionSub::~InstructionSub(void)
{
	if (InstructionSub::_debug)
		std::cout << "InstructionSub:: Destructor called." << std::endl;
	return ;
}

InstructionSub		&InstructionSub::operator=(InstructionSub const &rhs)
{
	if (InstructionSub::_debug)
		std::cout << "InstructionSub:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionSub::getType(void) const
{
	return (this->_type);
}

void					InstructionSub::execute(AvmCore &avm) const
{
	if (avm.getStack().size() < 2)
	{
		if (!avm.getStack().size())
			throw(AvmCore::StackTooSmall("Trying Sub with a empty stack"));
		throw(AvmCore::StackTooSmall("Trying Sub with a too small stack"));
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
