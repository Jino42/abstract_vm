#include <iostream>
#include "FactoryOperand.hpp"

FactoryOperand::FactoryOperand(void) :
_createOperand(FactoryOperand::_createMapCreateOperand())
{
	if (FactoryOperand::_debug)
		std::cout << "FactoryOperand:: Default constructor called." << std::endl;
	return ;
}

FactoryOperand::FactoryOperand(FactoryOperand const &src) :
_createOperand(FactoryOperand::_createMapCreateOperand())
{
	if (FactoryOperand::_debug)
		std::cout << "FactoryOperand:: Copy constructor called." << std::endl;
	*this = src;
	return ;
}

FactoryOperand::~FactoryOperand(void)
{
	if (FactoryOperand::_debug)
		std::cout << "FactoryOperand:: Destructor called." << std::endl;
	return ;
}

FactoryOperand		&FactoryOperand::operator=(FactoryOperand const &rhs)
{
	if (FactoryOperand::_debug)
		std::cout << "FactoryOperand:: Assignement called." << std::endl;
	if (this != &rhs)
	{
	}
	return (*this);
}


IOperand const		*FactoryOperand::createOperand(eOperandType type, std::string const &value) const
{
	return((this->*_createOperand.at(type))(value));
}

IOperand const		*FactoryOperand::_createInt8(std::string const &value) const
{
	return (new Operand<int8_t>(Int8, stod(value)));
}
IOperand const		*FactoryOperand::_createInt16(std::string const &value) const
{
	return (new Operand<int16_t>(Int16, stod(value)));
}
IOperand const		*FactoryOperand::_createInt32(std::string const &value) const
{
	return (new Operand<int32_t>(Int32, stod(value)));
}
IOperand const		*FactoryOperand::_createFloat(std::string const &value) const
{
	return (new Operand<float>(Float, stod(value)));
}
IOperand const		*FactoryOperand::_createDouble(std::string const &value) const
{
	return (new Operand<double>(Double, stod(value)));
}



//			NO MEMBER			//

std::map< eOperandType, IOperand const *(FactoryOperand::*)(std::string const &) const > const	FactoryOperand::_createMapCreateOperand(void)
{
	std::map< eOperandType, IOperand const *(FactoryOperand::*)(std::string const &) const > _createOperand;

	_createOperand[Int8] = &FactoryOperand::_createInt8;
	_createOperand[Int16] = &FactoryOperand::_createInt16;
	_createOperand[Int32] = &FactoryOperand::_createInt32;
	_createOperand[Float] = &FactoryOperand::_createFloat;
	_createOperand[Double] = &FactoryOperand::_createDouble;
	return (_createOperand);
}

const bool		FactoryOperand::_debug = 0;
