#include <iostream>
#include "InstructionException.hpp"

InstructionException::InstructionException(void)
{
	if (InstructionException::_debug)
		std::cout << "InstructionException:: Default constructor called." << std::endl;
	return ;
}

InstructionException::~InstructionException(void)
{
	if (InstructionException::_debug)
		std::cout << "InstructionException:: Destructor called." << std::endl;
	return ;
}

void					InstructionException::checkOverflow(eOperandType e, long double value)
{
	if (e == Int8)
	{
		if (value > std::numeric_limits<char>::max())
			throw(InstructionException::Overflow("You will make an Int8 Overflow"));
		if (value < std::numeric_limits<char>::min())
			throw(InstructionException::Underflow("You will make an Int8 Underflow"));
	}
	else if (e == Int16)
	{
		if (value > std::numeric_limits<short>::max())
			throw(InstructionException::Overflow("You will make an Int16 Overflow"));
		if (value < std::numeric_limits<short>::min())
			throw(InstructionException::Underflow("You will make an Int16 Underflow"));
	}
	else if (e == Int32)
	{
		if (value > std::numeric_limits<int>::max())
			throw(InstructionException::Overflow("You will make an Int32 Overflow"));
		if (value < std::numeric_limits<int>::min())
			throw(InstructionException::Underflow("You will make an Int32 Underflow"));
	}
	else if (e == Float)
	{
		if (value > std::numeric_limits<float>::max())
			throw(InstructionException::Overflow("You will make an Float Overflow"));
		if (value < -std::numeric_limits<float>::max())
			throw(InstructionException::Underflow("You will make an Float Underflow"));
	}
	else if (e == Double)
	{
		if (value > std::numeric_limits<double>::max())
			throw(InstructionException::Overflow("You will make an Double Overflow"));
		if (value < -std::numeric_limits<double>::max())
			throw(InstructionException::Underflow("You will make an Double Underflow"));
	}
}


const bool		InstructionException::_debug = 0;

InstructionException::Underflow::~Underflow(void) throw(){}
InstructionException::Underflow::Underflow(void) throw() :
	underflow_error(this->_error),
	_error("You make a Underflow") {}
InstructionException::Underflow::Underflow(std::string s) throw() :
	underflow_error(s),
	_error(s) { }
InstructionException::Underflow::Underflow(InstructionException::Underflow const &src) throw() :
	underflow_error(this->_error),
	_error(src._error)
	{ this->_error = src._error; }
const char	*InstructionException::Underflow::what() const throw()
	{ return (this->_error.c_str()); }

InstructionException::Overflow::~Overflow(void) throw(){}
InstructionException::Overflow::Overflow(void) throw() :
	overflow_error(this->_error),
	_error("You make a Overflow") {}
InstructionException::Overflow::Overflow(std::string s) throw() :
	overflow_error(s),
	_error(s) { }
InstructionException::Overflow::Overflow(InstructionException::Overflow const &src) throw() :
	overflow_error(this->_error),
	_error(src._error)
	{ this->_error = src._error; }
const char	*InstructionException::Overflow::what() const throw()
	{ return (this->_error.c_str()); }

InstructionException::StackTooSmall::~StackTooSmall(void) throw(){}
InstructionException::StackTooSmall::StackTooSmall(void) throw() :
	logic_error(this->_error),
	_error("Trying operate with a too small stack") {}
InstructionException::StackTooSmall::StackTooSmall(std::string s) throw() :
	logic_error(s),
	_error(s) { }
InstructionException::StackTooSmall::StackTooSmall(InstructionException::StackTooSmall const &src) throw() :
	logic_error(this->_error),
	_error(src._error)
	{ this->_error = src._error; }
const char	*InstructionException::StackTooSmall::what() const throw()
	{ return (this->_error.c_str()); }

InstructionException::ModByZero::~ModByZero(void) throw(){}
InstructionException::ModByZero::ModByZero(void) throw() :
	domain_error(this->_error),
	_error("Trying Modulo by 0") {}
InstructionException::ModByZero::ModByZero(std::string s) throw() :
	domain_error(s),
	_error(s) { }
InstructionException::ModByZero::ModByZero(InstructionException::ModByZero const &src) throw() :
	domain_error(this->_error),
	_error(src._error)
	{ this->_error = src._error; }
const char	*InstructionException::ModByZero::what() const throw()
	{ return (this->_error.c_str()); }

InstructionException::DivByZero::~DivByZero(void) throw(){}
InstructionException::DivByZero::DivByZero(void) throw() :
	domain_error(this->_error),
	_error("Trying Divide by 0") {}
InstructionException::DivByZero::DivByZero(std::string s) throw() :
	domain_error(s),
	_error(s) { }
InstructionException::DivByZero::DivByZero(InstructionException::DivByZero const &src) throw() :
	domain_error(this->_error),
	_error(src._error)
	{ this->_error = src._error; }
const char	*InstructionException::DivByZero::what() const throw()
	{ return (this->_error.c_str()); }


InstructionException::AssertFailed::~AssertFailed(void) throw(){}
InstructionException::AssertFailed::AssertFailed(void) throw() :
	runtime_error(this->_error),
	_error("Your assert failed") {}
InstructionException::AssertFailed::AssertFailed(std::string s) throw() :
	runtime_error(s),
	_error(s) { }
InstructionException::AssertFailed::AssertFailed(InstructionException::AssertFailed const &src) throw() :
	runtime_error(this->_error),
	_error(src._error)
	{ this->_error = src._error; }
const char	*InstructionException::AssertFailed::what() const throw()
	{ return (this->_error.c_str()); }
