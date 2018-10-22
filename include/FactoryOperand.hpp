#ifndef FACTORYOPERAND_HPP
# define FACTORYOPERAND_HPP

#include "IOperand.hpp"
#include <string>
#include <map>

class FactoryOperand {

public:

	~FactoryOperand(void);


	IOperand const			*createOperand(eOperandType type, std::string const & value, int precision) const;

	static FactoryOperand const	*getInstance(void);
	static void					deleteInstance(void);
	static int					getStringPrecision(std::string const &value);

private:

	static FactoryOperand	*_singleton;

	std::map< eOperandType, IOperand const *(FactoryOperand::*)(std::string const &, int) const > const	_createOperand;

	IOperand const		*_createInt8(std::string const & value, int precision) const;
	IOperand const		*_createInt16(std::string const & value, int precision) const;
	IOperand const		*_createInt32(std::string const & value, int precision) const;
	IOperand const		*_createFloat(std::string const & value, int precision) const;
	IOperand const		*_createDouble(std::string const & value, int precision) const;

	FactoryOperand		&operator=(FactoryOperand const &rhs) = delete;
	FactoryOperand(FactoryOperand const &src) = delete;
	FactoryOperand(void);



	static std::map< eOperandType, IOperand const *(FactoryOperand::*)(std::string const &, int) const > const	_createMapCreateOperand(void);
	static const bool	_debug;
};

#endif
