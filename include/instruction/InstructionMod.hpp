#ifndef INSTRUCTIONMOD_HPP
# define INSTRUCTIONMOD_HPP

#include "IInstruction.hpp"

class InstructionMod : public IInstruction {

public:

	InstructionMod(void);
	~InstructionMod(void);

	InstructionMod(InstructionMod const &src);
	InstructionMod		&operator=(InstructionMod const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;

	static const bool	_debug;
};

#endif
