#ifndef FACTORYOPERAND_HPP
# define FACTORYOPERAND_HPP

#include "Operand.tpp"
#include <string>
#include <map>

class FactoryOperand {

public:

	FactoryOperand(void);
	FactoryOperand(FactoryOperand const &src);
	~FactoryOperand(void);

	FactoryOperand		&operator=(FactoryOperand const &rhs);

	IOperand const		*createOperand( eOperandType type, std::string const & value ) const;

private:

	std::map< eOperandType, IOperand const *(FactoryOperand::*)(std::string const &) const > const	_createOperand;

	IOperand const		*_createInt8( std::string const & value ) const;
	IOperand const		*_createInt16( std::string const & value ) const;
	IOperand const		*_createInt32( std::string const & value ) const;
	IOperand const		*_createFloat( std::string const & value ) const;
	IOperand const		*_createDouble( std::string const & value ) const;

	static std::map< eOperandType, IOperand const *(FactoryOperand::*)(std::string const &) const > const	_createMapCreateOperand(void);
	static const bool	_debug;
};

#endif
