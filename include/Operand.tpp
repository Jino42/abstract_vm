#ifndef OPERAND_TPP
# define OPERAND_TPP

#include "IOperand.hpp"

template < typename T >
class Operand : public IOperand {

public:

	Operand(eOperandType e, T const &value) :
		_eOperandType(e),
		_value(value)
		{ }
	Operand(Operand<T> const &src) :
		_eOperandType(src._eOperandType),
		_value(src._value)
	{
		*this = src;
	}
	~Operand(void) { }

	eOperandType		getType(void) const
	{
		return (this->_eOperandType);
	}


private:
	eOperandType const	_eOperandType;
	T			 const	_value;

	Operand				&operator=(Operand const &rhs);
	Operand(void);
	static const bool	_debug;
};

#endif
