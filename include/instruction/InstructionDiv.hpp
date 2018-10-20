#ifndef INSTRUCTIONDIV_HPP
# define INSTRUCTIONDIV_HPP

#include "IInstruction.hpp"

class InstructionDiv : public IInstruction {

public:

	InstructionDiv(void);
	~InstructionDiv(void);

	InstructionDiv(InstructionDiv const &src);
	InstructionDiv		&operator=(InstructionDiv const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;

	static const bool	_debug;
};

#endif
