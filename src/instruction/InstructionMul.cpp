#include <iostream>
#include "InstructionMul.hpp"
#include "AvmCore.hpp"
#include "InstructionException.hpp"

InstructionMul::InstructionMul(void) :
_type(Mul)
{
	if (InstructionMul::_debug)
		std::cout << "InstructionMul:: Default constructor called." << std::endl;
	return ;
}

InstructionMul::InstructionMul(InstructionMul const &src) :
_type(Mul)
{
	if (InstructionMul::_debug)
		std::cout << "InstructionMul:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionMul::~InstructionMul(void)
{
	if (InstructionMul::_debug)
		std::cout << "InstructionMul:: Destructor called." << std::endl;
	return ;
}

InstructionMul		&InstructionMul::operator=(InstructionMul const &rhs)
{
	if (InstructionMul::_debug)
		std::cout << "InstructionMul:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionMul::getType(void) const
{
	return (this->_type);
}

void					InstructionMul::execute(AvmCore &avm) const
{
	if (avm.getStack().size() < 2)
	{
		if (!avm.getStack().size())
			throw(InstructionException::StackTooSmall("Trying Mul with a empty stack"));
		throw(InstructionException::StackTooSmall("Trying Mul with a too small stack"));
	}

	IOperand const *v1 = avm.getStack().top();
	avm.getStack().pop();
	IOperand const *v2 = avm.getStack().top();
	avm.getStack().pop();

	avm.getStack().push(*v2 * *v1);
	delete v1;
	delete v2;
}

const bool		InstructionMul::_debug = 0;
