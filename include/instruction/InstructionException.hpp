#ifndef INSTRUCTIONEXCEPTION_HPP
# define INSTRUCTIONEXCEPTION_HPP

#include <climits>
#include "IOperand.hpp"

class InstructionException {

public:

	class Underflow : public std::underflow_error {
	public:
		Underflow(void) throw();
		Underflow(std::string) throw();
		virtual const char* what() const throw();
		~Underflow(void) throw();
		Underflow(Underflow const &src) throw();
	private:
		Underflow &operator=(Underflow const &rhs) throw();
		std::string			_error;
	};

	class Overflow : public std::overflow_error {
	public:
		Overflow(void) throw();
		Overflow(std::string) throw();
		virtual const char* what() const throw();
		~Overflow(void) throw();
		Overflow(Overflow const &src) throw();
	private:
		Overflow &operator=(Overflow const &rhs) throw();
		std::string			_error;
	};

	class StackTooSmall : public std::logic_error {
	public:
		StackTooSmall(void) throw();
		StackTooSmall(std::string) throw();
		virtual const char* what() const throw();
		~StackTooSmall(void) throw();
		StackTooSmall(StackTooSmall const &src) throw();
	private:
		StackTooSmall &operator=(StackTooSmall const &rhs) throw();
		std::string			_error;
	};

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

	class ModByZero : public std::domain_error {
	public:
		ModByZero(void) throw();
		ModByZero(std::string) throw();
		virtual const char* what() const throw();
		~ModByZero(void) throw();
		ModByZero(ModByZero const &src) throw();
	private:
		ModByZero &operator=(ModByZero const &rhs) throw();
		std::string			_error;
	};

	class DivByZero : public std::domain_error {
	public:
		DivByZero(void) throw();
		DivByZero(std::string) throw();
		virtual const char* what() const throw();
		~DivByZero(void) throw();
		DivByZero(DivByZero const &src) throw();
	private:
		DivByZero &operator=(DivByZero const &rhs) throw();
		std::string			_error;
	};

	InstructionException(void);
	~InstructionException(void);

	static void			checkOverflow(eOperandType e, long double value);


private:
	InstructionException(InstructionException const &src);
	InstructionException		&operator=(InstructionException const &rhs);

	static const bool	_debug;
};

#endif
