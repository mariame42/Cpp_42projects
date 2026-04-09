#include "sorting_helpers/sorting_helpers.hpp"
#include <algorithm>

std::vector<int> SortingHelpers::mergeInsertSortRecursive(const std::vector<int>& chain)
{
    if (chain.size() <= 1)
        return chain;

    std::vector<int> localPending;
    std::vector<int> localMain;
    bool hasStraggler = false;
    int straggler = 0;

    for (std::size_t i = 0; i + 1 < chain.size(); i += 2)
    {
        int a = chain[i];
        int b = chain[i + 1];
        if (a < b)
        {
            localPending.push_back(a);
            localMain.push_back(b);
        }
        else
        {
            localPending.push_back(b);
            localMain.push_back(a);
        }
    }
    if (chain.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = chain.back();
    }

    std::vector<int> sortedMain = mergeInsertSortRecursive(localMain);

    for (std::size_t i = 0; i < localPending.size(); ++i)
    {
        std::vector<int>::iterator pos = std::lower_bound(sortedMain.begin(), sortedMain.end(), localPending[i]);
        sortedMain.insert(pos, localPending[i]);
    }
    if (hasStraggler)
    {
        std::vector<int>::iterator pos = std::lower_bound(sortedMain.begin(), sortedMain.end(), straggler);
        sortedMain.insert(pos, straggler);
    }
    return sortedMain;
}


void SortingHelpers::insertPending(std::vector<int>& sortedMain, const std::vector<int>& pending)
{
    for (std::size_t i = 0; i < pending.size(); ++i)
    {
        std::vector<int>::iterator pos = std::lower_bound(sortedMain.begin(), sortedMain.end(), pending[i]);
        sortedMain.insert(pos, pending[i]);
    }
}

void SortingHelpers::splitPairs(const std::vector<int>& input,
                                std::vector<int>& pending,
                                std::vector<int>& mainChain,
                                bool& hasStraggler,
                                int& straggler)
{
    pending.clear();
    mainChain.clear();
    hasStraggler = false;
    straggler = 0;

    for (std::size_t i = 0; i + 1 < input.size(); i += 2)
    {
        int a = input[i];
        int b = input[i + 1];
        if (a < b)
        {
            pending.push_back(a);
            mainChain.push_back(b);
        }
        else
        {
            pending.push_back(b);
            mainChain.push_back(a);
        }
    }
    if (input.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = input.back();
    }
}