#include <iostream>
#include "AInstruction.hpp"

AInstruction::AInstruction(std::string const &instruction, eInstructionType type) :
_instruction(instruction),
_type(type)
{
	return ;
}

AInstruction::~AInstruction(void)
{
	return ;
}

eInstructionType		AInstruction::getType(void) const
{
	return (this->_type);
}

std::string				AInstruction::toString(void) const
{
	return (this->_instruction);
}
