#include <iostream>
#include "FactoryInstruction.hpp"
#include "InstructionAdd.hpp"
#include "InstructionDiv.hpp"
#include "InstructionDump.hpp"
#include "InstructionExit.hpp"
#include "InstructionMod.hpp"
#include "InstructionMul.hpp"
#include "InstructionPrint.hpp"
#include "InstructionPop.hpp"
#include "InstructionSub.hpp"
#include "InstructionPush.hpp"
#include "InstructionAssert.hpp"

FactoryInstruction::FactoryInstruction(void) :
_createInstruction(FactoryInstruction::_createMapInstruction()),
_createInstructionArg(FactoryInstruction::_createMapInstructionArg())
{
	if (FactoryInstruction::_debug)
		std::cout << "FactoryInstruction:: Default constructor called." << std::endl;
	return ;
}

FactoryInstruction::~FactoryInstruction(void)
{
	if (FactoryInstruction::_debug)
		std::cout << "FactoryInstruction:: Destructor called." << std::endl;
	return ;
}

AInstruction const		*FactoryInstruction::createInstruction(std::string const &instruction, eInstructionType type, IOperand const *operand) const
{
	return((this->*_createInstructionArg.at(type))(instruction, operand));
}
AInstruction const		*FactoryInstruction::createInstruction(eInstructionType type) const
{
	return((this->*_createInstruction.at(type))());
}

AInstruction const		*FactoryInstruction::_createPush(std::string const &instruction, IOperand const *operand) const
{
	return (new InstructionPush(instruction, operand));
}
AInstruction const		*FactoryInstruction::_createAssert(std::string const &instruction, IOperand const *operand) const
{
	return (new InstructionAssert(instruction, operand));
}

std::map< eInstructionType, FactoryInstruction::functionCreateArg > const	FactoryInstruction::_createMapInstructionArg(void)
{
	std::map< eInstructionType, FactoryInstruction::functionCreateArg > _createInstructionArg;

	_createInstructionArg[Push] = &FactoryInstruction::_createPush;
	_createInstructionArg[Assert] = &FactoryInstruction::_createAssert;
	return (_createInstructionArg);
}


AInstruction const		*FactoryInstruction::_createPop(void) const
{
	return (new InstructionPop());
}
AInstruction const		*FactoryInstruction::_createDump(void) const
{
	return (new InstructionDump());
}
AInstruction const		*FactoryInstruction::_createAdd(void) const
{
	return (new InstructionAdd());
}
AInstruction const		*FactoryInstruction::_createSub(void) const
{
	return (new InstructionSub());
}
AInstruction const		*FactoryInstruction::_createMul(void) const
{
	return (new InstructionMul());
}
AInstruction const		*FactoryInstruction::_createDiv(void) const
{
	return (new InstructionDiv());
}
AInstruction const		*FactoryInstruction::_createMod(void) const
{
	return (new InstructionMod());
}
AInstruction const		*FactoryInstruction::_createPrint(void) const
{
	return (new InstructionPrint());
}
AInstruction const		*FactoryInstruction::_createExit(void) const
{
	return (new InstructionExit());
}

std::map< eInstructionType, FactoryInstruction::functionCreate > const	FactoryInstruction::_createMapInstruction(void)
{
	std::map< eInstructionType, FactoryInstruction::functionCreate > _createInstruction;

	_createInstruction[Pop] = &FactoryInstruction::_createPop;
	_createInstruction[Dump] = &FactoryInstruction::_createDump;
	_createInstruction[Add] = &FactoryInstruction::_createAdd;
	_createInstruction[Sub] = &FactoryInstruction::_createSub;
	_createInstruction[Mul] = &FactoryInstruction::_createMul;
	_createInstruction[Div] = &FactoryInstruction::_createDiv;
	_createInstruction[Mod] = &FactoryInstruction::_createMod;
	_createInstruction[Print] = &FactoryInstruction::_createPrint;
	_createInstruction[Exit] = &FactoryInstruction::_createExit;
	return (_createInstruction);
}

const bool		FactoryInstruction::_debug = 0;
