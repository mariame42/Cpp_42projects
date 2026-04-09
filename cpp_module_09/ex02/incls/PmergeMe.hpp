#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

#include "utils/PrintWithColor.hpp"
#include "utils/ErrorMessages.hpp"

class PmergeMe
{
    private :
        double _vectorTime;
        double _dequeTime;

        std::vector<int> _vector;
        std::deque<int> _deque;

        std::vector<int> _sortedVector;
        std::deque<int> _sortedDeque;

        std::vector<int> _pendingVector;
        std::vector<int> _mainChainVector;
        std::deque<int> _pendingDeque;
        std::deque<int> _mainChainDeque;

        bool _hasStragglerVector;
        int _stragglerVector;
        bool _hasStragglerDeque;
        int _stragglerDeque;

        std::vector<int> _parsedInput;

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