#include <iostream>
#include "InstructionAssert.hpp"
#include "AvmCore.hpp"

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
			throw(AvmCore::StackTooSmall("Trying Add with a empty stack"));
	}

	IOperand const *v1 = avm.getStack().top();

	if (v1->toString() != this->_value->toString())
		throw(InstructionAssert::AssertFailed("Assert failed : [" + v1->toString() + " != " + this->_value->toString() + "]"));
}

const bool		InstructionAssert::_debug = 0;

InstructionAssert::AssertFailed::~AssertFailed(void) throw(){}
InstructionAssert::AssertFailed::AssertFailed(void) throw() :
	runtime_error(this->_error),
	_error("Your assert failed") {}
InstructionAssert::AssertFailed::AssertFailed(std::string s) throw() :
	runtime_error(s),
	_error(s) { }
InstructionAssert::AssertFailed::AssertFailed(InstructionAssert::AssertFailed const &src) throw() :
	runtime_error(this->_error),
	_error(src._error)
	{ this->_error = src._error; }
const char	*InstructionAssert::AssertFailed::what() const throw()
	{ return (this->_error.c_str()); }
