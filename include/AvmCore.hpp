#ifndef AVMCORE_HPP
# define AVMCORE_HPP

class AvmCore {

public:

	AvmCore(void);
	~AvmCore(void);

	void		parse(std::string const &path);

private:

	AvmCore(AvmCore const &src);
	AvmCore		&operator=(AvmCore const &rhs);

	static const bool	_debug;
};

#endif
