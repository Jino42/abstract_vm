#include <iostream>
#include "InstructionPush.hpp"
#include "AvmCore.hpp"
#include "FactoryOperand.hpp"
#include "InstructionException.hpp"

InstructionPush::InstructionPush(std::string const &instruction, IOperand const *operand) :
AInstruction(instruction, Push),
_value(operand)
{
	if (InstructionPush::_debug)
		std::cout << "InstructionPush:: Default constructor called." << std::endl;
	return ;
}

InstructionPush::~InstructionPush(void)
{
	if (InstructionPush::_debug)
		std::cout << "InstructionPush:: Destructor called." << std::endl;
	if (this->_value)
		delete this->_value;
	return ;
}

void					InstructionPush::execute(AvmCore &avm) const
{
	avm.getStack().push(
			FactoryOperand::getInstance()->createOperand(
													this->_value->getType(),
													this->_value->toString(),
													this->_value->getPrecision()));
}

const bool		InstructionPush::_debug = 0;
