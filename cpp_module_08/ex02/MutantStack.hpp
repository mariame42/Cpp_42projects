#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

/*
 * std::stack is a container adapter for LIFO (Last In, First Out) access.
 * It wraps an underlying container (by default std::deque) but does not expose
 * iterators. The protected member 'c' in std::stack is that underlying container;
 * we use it in MutantStack to provide begin(), end(), etc.
 */

/*
 * LIFO (Last In First Out)
 *The last element added to the stack is the first one to be removed.
 */

// -------------------------- INCLUDES --------------------------
#include <stack>

// -------------------------- COLOR MACROS --------------------------
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

/*
 * Breaking down: typedef typename std::stack<T>::container_type::iterator iterator;
 *
 * - typedef creates an alias: typedef existing_type new_name;
 *
 * - std::stack<T> has a member typedef container_type (e.g. std::deque<T> by default).
 *   We use it instead of hardcoding std::deque<T> because the underlying container
 *   can be changed: std::stack<int, std::vector<int>> uses std::vector<int>.
 *
 * - typename is required in templates: until T is known, the compiler cannot tell
 *   whether container_type::iterator is a type or a static member. typename tells
 *   the compiler that iterator is a nested type name.
 */

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        // iterator is a type that can be used to iterate through the container
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        // reverse_iterator is a type that can be used to iterate through the container in reverse
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);

        // functions that return the iterator at the beginning and end of the container
        iterator begin();
        iterator end();

        // functions that return the const iterator at the beginning and end of the container
        const_iterator begin() const;
        const_iterator end() const;

        // functions that return the reverse iterator at the beginning and end of the container
        reverse_iterator rbegin();
        reverse_iterator rend();

        // functions that return the const reverse iterator at the beginning and end of the container
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
};

#include "MutantStack.tpp"

#endif