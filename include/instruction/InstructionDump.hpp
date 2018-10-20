#ifndef INSTRUCTIONDUMP_HPP
# define INSTRUCTIONDUMP_HPP

#include "IInstruction.hpp"

class InstructionDump : public IInstruction {

public:

	InstructionDump(void);
	~InstructionDump(void);

	InstructionDump(InstructionDump const &src);
	InstructionDump		&operator=(InstructionDump const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;

	static const bool	_debug;
};

#endif
