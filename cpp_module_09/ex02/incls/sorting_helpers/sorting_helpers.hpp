#ifndef SORTING_HELPERS_HPP
#define SORTING_HELPERS_HPP

#include <vector>
#include <deque>
namespace SortingHelpers
{
    std::vector<int> mergeInsertSortRecursive(const std::vector<int>& chain);
    void insertPending(std::vector<int>& sortedMain, const std::vector<int>& pending);
    void splitPairs(const std::vector<int>& input,
                    std::vector<int>& pending,
                    std::vector<int>& mainChain,
                    bool& hasStraggler,
                    int& straggler);

    std::deque<int> mergeInsertSortRecursive(const std::deque<int>& chain);
    void insertPending(std::deque<int>& sortedMain, const std::deque<int>& pending);
    void splitPairs(const std::deque<int>& input,
                    std::deque<int>& pending,
                    std::deque<int>& mainChain,
                    bool& hasStraggler,
                    int& straggler);
}

#endif