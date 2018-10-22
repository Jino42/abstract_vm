#include <iostream>
#include "InstructionPrint.hpp"
#include "InstructionException.hpp"
#include "AvmCore.hpp"
#include "InstructionException.hpp"

InstructionPrint::InstructionPrint(void) :
_type(Print)
{
	if (InstructionPrint::_debug)
		std::cout << "InstructionPrint:: Default constructor called." << std::endl;
	return ;
}

InstructionPrint::InstructionPrint(InstructionPrint const &src) :
_type(Print)
{
	if (InstructionPrint::_debug)
		std::cout << "InstructionPrint:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionPrint::~InstructionPrint(void)
{
	if (InstructionPrint::_debug)
		std::cout << "InstructionPrint:: Destructor called." << std::endl;
	return ;
}

InstructionPrint		&InstructionPrint::operator=(InstructionPrint const &rhs)
{
	if (InstructionPrint::_debug)
		std::cout << "InstructionPrint:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionPrint::getType(void) const
{
	return (this->_type);
}

void					InstructionPrint::execute(AvmCore &avm) const
{
	char c;
	if (avm.getStack().size() < 1)
	{
		if (!avm.getStack().size())
			throw(InstructionException::StackTooSmall("Trying Add with a empty stack"));
	}

	IOperand const *v1 = avm.getStack().top();

	if (v1->getType() != Int8)
		throw(InstructionException::AssertFailed("Print failed : [Type is not printable]"));
	c = std::stoi(v1->toString());
	std::cout << c;
}

const bool		InstructionPrint::_debug = 0;
