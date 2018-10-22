#ifndef INSTRUCTIONMOD_HPP
# define INSTRUCTIONMOD_HPP

#include "AInstruction.hpp"

class InstructionMod : public AInstruction {

public:

	InstructionMod(void);
	~InstructionMod(void);

	void				execute(AvmCore &avm) const;
private:

	InstructionMod(InstructionMod const &src);
	InstructionMod		&operator=(InstructionMod const &rhs);

	static const bool	_debug;
};

#endif
