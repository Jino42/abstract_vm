#include <iostream>
#include "FactoryInstruction.hpp"
#include "InstructionPop.hpp"

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

IInstruction const		*FactoryInstruction::createInstruction(eInstructionType type, std::string const &value) const
{
	return((this->*_createInstructionArg.at(type))(value));
}
IInstruction const		*FactoryInstruction::createInstruction(eInstructionType type) const
{
	return((this->*_createInstruction.at(type))());
}


std::map< eInstructionType, FactoryInstruction::functionCreateArg > const	FactoryInstruction::_createMapInstructionArg(void)
{
	std::map< eInstructionType, FactoryInstruction::functionCreateArg > _createInstructionArg;

//	_createInstructionArg[Push] = &FactoryInstruction::_createPush;
//	_createInstructionArg[Assert] = &FactoryInstruction::_createAssert;
	return (_createInstructionArg);
}


IInstruction const		*FactoryInstruction::_createPop(void) const
{
	return (new InstructionPop());
}

std::map< eInstructionType, FactoryInstruction::functionCreate > const	FactoryInstruction::_createMapInstruction(void)
{
	std::map< eInstructionType, FactoryInstruction::functionCreate > _createInstruction;

	_createInstruction[Pop] = &FactoryInstruction::_createPop;
	/*_createInstruction[Dump] = &FactoryInstruction::_createDump;
	_createInstruction[Add] = &FactoryInstruction::_createAdd;
	_createInstruction[Sub] = &FactoryInstruction::_createSub;
	_createInstruction[Mul] = &FactoryInstruction::_createMul;
	_createInstruction[Div] = &FactoryInstruction::_createDiv;
	_createInstruction[Mod] = &FactoryInstruction::_createMod;
	_createInstruction[Print] = &FactoryInstruction::_createPrint;
	_createInstruction[Exit] = &FactoryInstruction::_createExit;*/
	return (_createInstruction);
}

const bool		FactoryInstruction::_debug = 0;
