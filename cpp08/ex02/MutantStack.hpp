#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iterator>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	MutantStack();
	MutantStack(const MutantStack& p);
	~MutantStack();
	MutantStack& operator= (const MutantStack& p);
	iterator begin();
	const_iterator cbegin() const;
	iterator end();
	const_iterator cend() const;
};

template <class T, class Container> MutantStack<T, Container>::MutantStack()
{
}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& p)
	: std::stack<T, Container>(p)
{
}

template <class T, class Container>
MutantStack<T, Container>&
MutantStack<T, Container>::operator= (const MutantStack<T, Container>& p)
{
	std::stack<T, Container>::c = p.c;
	return *this;
}

template <class T, class Container> MutantStack<T, Container>::~MutantStack()
{
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin()
{
	return std::stack<T, Container>::c.begin();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::cbegin() const
{
	return std::stack<T, Container>::c.cbegin();
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end()
{
	return std::stack<T, Container>::c.end();
}

template <class T, class Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::cend() const
{
	return std::stack<T, Container>::c.cend();
}

#endif
