#ifndef INSTRUCTIONPUSH_HPP
# define INSTRUCTIONPUSH_HPP

#include "IInstruction.hpp"
#include <string>

class InstructionPush : public IInstruction {

public:

	InstructionPush(std::string const &);
	~InstructionPush(void);

	InstructionPush(InstructionPush const &src);
	InstructionPush		&operator=(InstructionPush const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;
	std::string const		_value;

	InstructionPush(void);

	static const bool	_debug;
};

#endif
