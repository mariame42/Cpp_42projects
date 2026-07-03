#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

#ifndef WITH_ERROR_DETAILS
# define WITH_ERROR_DETAILS 0
#endif

#include "utils/ErrorMessages.hpp"
#include "Pair.hpp"

#define DEBUG 0

/*
    PmergeMe class
    This class is used to merge and sort the input vectors and deques
    It uses the merge insert sort algorithm

    program steps :
        1. parse the input  + make sure the input is valid
        2. sort the input using the merge insert sort algorithm for both vector and deque
        for vector and deque, the sorting steps are the same :
            3. split the input into pairs
            4. sort the pairs by the big value "recursive sorting"
            5. build the main chain and the pending chain from the sorted pairs
            6. insert the pending chain into the main chain using the Jacobsthal sequence "binary sorting"
            7. if there is a straggler, insert it into the main chain
        8. print the sorted input for both vector and deque
        9. print the time taken to sort the input for both vector and deque
*/


class PmergeMe
{
    private :
        // resullts values
        double _vectorTime;
        double _dequeTime;
        std::vector<int> _sortedVector;
        std::deque<int> _sortedDeque;
            // parsed input values
            std::vector<int> _parsedInput;

        // vectors that will be sorted
        std::vector<int> _vector;
        std::deque<int> _deque;

        // pending and main chain values
        std::vector<int> _pendingVector;
        std::vector<int> _mainChainVector;
        std::deque<int> _pendingDeque;
        std::deque<int> _mainChainDeque;

        // straggler values
        bool _hasStragglerVector;
        int _stragglerVector;
        bool _hasStragglerDeque;
        int _stragglerDeque;

        // pairs values
        std::vector<Pair> _pairsVector;
        std::deque<Pair> _pairsDeque;

    public :
        // OCCF
        PmergeMe();
        PmergeMe(const PmergeMe& src);
        PmergeMe& operator=(const PmergeMe& src);
        ~PmergeMe();

        // parse
        void parse(const std::vector<std::string>& args);

        // sort
        void sortAndCalcForVector();
        void sortAndCalcForDeque();

        // print
        void printstanderdOutput();
};

#endif