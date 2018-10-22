#ifndef INSTRUCTIONASSERT_HPP
# define INSTRUCTIONASSERT_HPP

#include "IInstruction.hpp"
#include "IOperand.hpp"
#include <string>

class InstructionAssert : public IInstruction {

public:

	class AssertFailed : public std::runtime_error {
	public:
		AssertFailed(void) throw();
		AssertFailed(std::string) throw();
		virtual const char* what() const throw();
		~AssertFailed(void) throw();
		AssertFailed(AssertFailed const &src) throw();
	private:
		AssertFailed &operator=(AssertFailed const &rhs) throw();
		std::string			_error;
	};

	InstructionAssert(IOperand const *);
	~InstructionAssert(void);

	InstructionAssert(InstructionAssert const &src);
	InstructionAssert		&operator=(InstructionAssert const &rhs);

	void				execute(AvmCore &avm) const;
	eInstructionType	getType(void) const;
private:
	eInstructionType const	_type;
	IOperand const			*_value;

	InstructionAssert(void);

	static const bool	_debug;
};

#endif
