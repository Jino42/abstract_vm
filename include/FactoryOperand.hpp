#ifndef FACTORYOPERAND_HPP
# define FACTORYOPERAND_HPP

#include "IOperand.hpp"
#include <string>
#include <map>

class FactoryOperand {

public:

	~FactoryOperand(void);


	IOperand const			*createOperand(eOperandType type, std::string const & value) const;

	static FactoryOperand const	*getInstance(void);
	static void					deleteInstance(void);

private:

	static FactoryOperand	*_singleton;

	std::map< eOperandType, IOperand const *(FactoryOperand::*)(std::string const &) const > const	_createOperand;

	IOperand const		*_createInt8( std::string const & value ) const;
	IOperand const		*_createInt16( std::string const & value ) const;
	IOperand const		*_createInt32( std::string const & value ) const;
	IOperand const		*_createFloat( std::string const & value ) const;
	IOperand const		*_createDouble( std::string const & value ) const;

	FactoryOperand		&operator=(FactoryOperand const &rhs) = delete;
	FactoryOperand(FactoryOperand const &src) = delete;
	FactoryOperand(void);
	static std::map< eOperandType, IOperand const *(FactoryOperand::*)(std::string const &) const > const	_createMapCreateOperand(void);
	static const bool	_debug;
};

#endif
