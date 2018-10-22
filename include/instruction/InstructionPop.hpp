#ifndef INSTRUCTIONPOP_HPP
# define INSTRUCTIONPOP_HPP

#include "AInstruction.hpp"

class InstructionPop : public AInstruction {

public:

	InstructionPop(void);
	~InstructionPop(void);

	void				execute(AvmCore &avm) const;
private:

	InstructionPop(InstructionPop const &src);
	InstructionPop		&operator=(InstructionPop const &rhs);

	static const bool	_debug;
};

#endif
