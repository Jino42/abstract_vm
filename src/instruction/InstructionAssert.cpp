#include <iostream>
#include "InstructionAssert.hpp"
#include "AvmCore.hpp"
#include "InstructionException.hpp"

InstructionAssert::InstructionAssert(IOperand const *operand) :
_type(Assert),
_value(operand)
{
	if (InstructionAssert::_debug)
		std::cout << "InstructionAssert:: Default constructor called." << std::endl;
	return ;
}

InstructionAssert::InstructionAssert(InstructionAssert const &src) :
_type(Assert),
_value(src._value)
{
	if (InstructionAssert::_debug)
		std::cout << "InstructionAssert:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

InstructionAssert::~InstructionAssert(void)
{
	if (InstructionAssert::_debug)
		std::cout << "InstructionAssert:: Destructor called." << std::endl;
	if (this->_value)
		delete this->_value;
	return ;
}

InstructionAssert		&InstructionAssert::operator=(InstructionAssert const &rhs)
{
	if (InstructionAssert::_debug)
		std::cout << "InstructionAssert:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}

eInstructionType		InstructionAssert::getType(void) const
{
	return (this->_type);
}

void					InstructionAssert::execute(AvmCore &avm) const
{
	if (avm.getStack().size() < 1)
	{
		if (!avm.getStack().size())
			throw(InstructionException::StackTooSmall("Trying Add with a empty stack"));
	}

	IOperand const *v1 = avm.getStack().top();

	if (v1->toString() != this->_value->toString())
		throw(InstructionException::AssertFailed("Assert failed : [" + v1->toString() + " != " + this->_value->toString() + "]"));
	if (v1->getType() != this->_value->getType())
		throw(InstructionException::AssertFailed("Assert failed : [Type are different]"));
}

const bool		InstructionAssert::_debug = 0;
