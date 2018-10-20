#ifndef INSTRUCTIONPRINT_HPP
# define INSTRUCTIONPRINT_HPP

#include "IInstruction.hpp"

class InstructionPrint : public IInstruction {

public:

	InstructionPrint(void);
	~InstructionPrint(void);

	InstructionPrint(InstructionPrint const &src);
	InstructionPrint		&operator=(InstructionPrint const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;

	static const bool	_debug;
};

#endif
