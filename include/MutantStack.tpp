#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template < typename T >
class MutantStack : public std::stack<T> {

public:

	MutantStack(void) {}
	~MutantStack(void) {}
	MutantStack(MutantStack const &rhs) { this = rhs; }
	MutantStack& operator=(MutantStack const &rhs) { this->c = rhs.c; return (*this); }

	typedef typename MutantStack< T >::container_type::iterator iterator;

	iterator	begin();
	iterator	end();
	iterator	rbegin();
	iterator	rend();

private:

};

template < typename T >
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template < typename T >
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return this->c.end();
}

template < typename T >
typename MutantStack<T>::iterator	MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template < typename T >
typename MutantStack<T>::iterator	MutantStack<T>::rend()
{
	return this->c.rend();
}

#endif
