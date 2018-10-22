#ifndef INSTRUCTIONDUMP_HPP
# define INSTRUCTIONDUMP_HPP

#include "AInstruction.hpp"

class InstructionDump : public AInstruction {

public:

	InstructionDump(void);
	~InstructionDump(void);

	void				execute(AvmCore &avm) const;
private:

	InstructionDump(InstructionDump const &src);
	InstructionDump		&operator=(InstructionDump const &rhs);

	static const bool	_debug;
};

#endif
