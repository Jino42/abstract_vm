#ifndef INSTRUCTIONPRINT_HPP
# define INSTRUCTIONPRINT_HPP

#include "AInstruction.hpp"

class InstructionPrint : public AInstruction {

public:

	InstructionPrint(void);
	~InstructionPrint(void);

	void				execute(AvmCore &avm) const;
private:

	InstructionPrint(InstructionPrint const &src);
	InstructionPrint		&operator=(InstructionPrint const &rhs);

	static const bool	_debug;
};

#endif
