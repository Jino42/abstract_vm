#ifndef FACTORYINSTRUCTION_HPP
# define FACTORYINSTRUCTION_HPP

#include <map>
#include <stdexcept>
#include "AInstruction.hpp"
#include "IOperand.hpp"

class FactoryInstruction {

public:

	typedef AInstruction const *(FactoryInstruction::*functionCreateArg)(std::string const &, IOperand const *) const;
	typedef AInstruction const *(FactoryInstruction::*functionCreate)(void) const;

	FactoryInstruction(void);
	~FactoryInstruction(void);

	AInstruction const		*createInstruction(std::string const &, eInstructionType type, IOperand const *) const;
	AInstruction const		*createInstruction(eInstructionType type) const;

private:
	std::map<eInstructionType, functionCreate> const		_createInstruction;
	std::map<eInstructionType, functionCreateArg> const		_createInstructionArg;

	AInstruction const		*_createPush(std::string const &, IOperand const *) const;
	AInstruction const		*_createAssert(std::string const &, IOperand const *) const;


	AInstruction const		*_createPop(void) const;
	AInstruction const		*_createDump(void) const;
	AInstruction const		*_createAdd(void) const;
	AInstruction const		*_createSub(void) const;
	AInstruction const		*_createMul(void) const;
	AInstruction const		*_createDiv(void) const;
	AInstruction const		*_createMod(void) const;
	AInstruction const		*_createPrint(void) const;
	AInstruction const		*_createExit(void) const;

	FactoryInstruction(FactoryInstruction const &src);
	FactoryInstruction		&operator=(FactoryInstruction const &rhs);

	static std::map< eInstructionType, functionCreate > const		_createMapInstruction(void);
	static std::map< eInstructionType, functionCreateArg > const	_createMapInstructionArg(void);
	static const bool	_debug;
};

#endif
