// Subject: CPP Module 07 - ex00 (Whatever)
// Purpose: Provide generic swap, min and max templates.

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const &max(T const &a, T const &b)
{
	return (a > b ? a : b);
}

template <typename T>
T const &min(T const &a, T const &b)
{
	return (a < b ? a : b);
}

#endif
