#ifndef SortingHelpers_HPP
#define SortingHelpers_HPP

#include <vector>
#include <deque>
#include "Pair.hpp"

/*
    SortingHelpers namespace
    This namespace is used to store the sorting helpers functions for both vector and deque
*/
namespace SortingHelpers
{
    // vector functions
    void splitPairs(
        const std::vector<int>& input,
        std::vector<Pair>& pairs,
        bool& hasStraggler,
        int& straggler);
    void buildChainsFromPairs(std::vector<Pair>& pairs, std::vector<int>& mainChain, std::vector<int>& pending);
    std::vector<int> mergeInsertSortRecursive(const std::vector<int>& chain);
    void insertPending(std::vector<int>& sortedMain, const std::vector<int>& pending);

    // deque functions
    void splitPairs(
        const std::deque<int>& input,
        std::deque<Pair>& pairs,
        bool& hasStraggler,
        int& straggler);
    void buildChainsFromPairs(std::deque<Pair>& pairs, std::deque<int>& mainChain, std::deque<int>& pending);
    std::deque<int> mergeInsertSortRecursive(const std::deque<int>& chain);
    void insertPending(std::deque<int>& sortedMain, const std::deque<int>& pending);
}

#endif