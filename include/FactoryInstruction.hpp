#ifndef FACTORYINSTRUCTION_HPP
# define FACTORYINSTRUCTION_HPP

#include <map>
#include <stdexcept>
#include "IInstruction.hpp"

class FactoryInstruction {

public:

	typedef IInstruction const *(FactoryInstruction::*functionCreate)(void) const;
	typedef IInstruction const *(FactoryInstruction::*functionCreateArg)(std::string const &) const;

	FactoryInstruction(void);
	~FactoryInstruction(void);

	IInstruction const		*createInstruction(eInstructionType type, std::string const &value) const;
	IInstruction const		*createInstruction(eInstructionType type) const;

private:
	std::map<eInstructionType, functionCreate> const		_createInstruction;
	std::map<eInstructionType, functionCreateArg> const		_createInstructionArg;

	IInstruction const		*_createPush(std::string const &) const;
	IInstruction const		*_createAssert(std::string const &) const;


	IInstruction const		*_createPop(void) const;
	IInstruction const		*_createDump(void) const;
	IInstruction const		*_createAdd(void) const;
	IInstruction const		*_createSub(void) const;
	IInstruction const		*_createMul(void) const;
	IInstruction const		*_createDiv(void) const;
	IInstruction const		*_createMod(void) const;
	IInstruction const		*_createPrint(void) const;
	IInstruction const		*_createExit(void) const;

	FactoryInstruction(FactoryInstruction const &src);
	FactoryInstruction		&operator=(FactoryInstruction const &rhs);

	static std::map< eInstructionType, functionCreate > const	_createMapInstruction(void);
	static std::map< eInstructionType, functionCreateArg > const	_createMapInstructionArg(void);
	static const bool	_debug;
};

#endif
