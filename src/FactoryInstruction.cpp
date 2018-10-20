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

IInstruction const		*FactoryInstruction::createInstruction(eInstructionType type, IOperand const *operand) const
{
	return((this->*_createInstructionArg.at(type))(operand));
}
IInstruction const		*FactoryInstruction::createInstruction(eInstructionType type) const
{
	return((this->*_createInstruction.at(type))());
}

IInstruction const		*FactoryInstruction::_createPush(IOperand const *operand) const
{
	return (new InstructionPush(operand));
}
IInstruction const		*FactoryInstruction::_createAssert(IOperand const *operand) const
{
	return (new InstructionAssert(operand));
}

std::map< eInstructionType, FactoryInstruction::functionCreateArg > const	FactoryInstruction::_createMapInstructionArg(void)
{
	std::map< eInstructionType, FactoryInstruction::functionCreateArg > _createInstructionArg;

	_createInstructionArg[Push] = &FactoryInstruction::_createPush;
	_createInstructionArg[Assert] = &FactoryInstruction::_createAssert;
	return (_createInstructionArg);
}


IInstruction const		*FactoryInstruction::_createPop(void) const
{
	return (new InstructionPop());
}
IInstruction const		*FactoryInstruction::_createDump(void) const
{
	return (new InstructionDump());
}
IInstruction const		*FactoryInstruction::_createAdd(void) const
{
	return (new InstructionAdd());
}
IInstruction const		*FactoryInstruction::_createSub(void) const
{
	return (new InstructionSub());
}
IInstruction const		*FactoryInstruction::_createMul(void) const
{
	return (new InstructionMul());
}
IInstruction const		*FactoryInstruction::_createDiv(void) const
{
	return (new InstructionDiv());
}
IInstruction const		*FactoryInstruction::_createMod(void) const
{
	return (new InstructionMod());
}
IInstruction const		*FactoryInstruction::_createPrint(void) const
{
	return (new InstructionPrint());
}
IInstruction const		*FactoryInstruction::_createExit(void) const
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
