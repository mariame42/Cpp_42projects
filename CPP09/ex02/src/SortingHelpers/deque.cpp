#include "SortingHelpers/SortingHelpers.hpp"
#include <algorithm>

/*
    step 01 in the algorithm : split the input into pairs
*/
void SortingHelpers::splitPairs(const std::deque<int>& input,
                                std::deque<Pair>& pairs,
                                bool& hasStraggler,
                                int& straggler)
{
    pairs.clear();
    hasStraggler = false;
    straggler = 0;

    for (std::size_t i = 0; i + 1 < input.size(); i += 2)
    {
        int a = input[i];
        int b = input[i + 1];

        if (a < b)
            pairs.push_back(Pair(b, a)); // big, small
        else
            pairs.push_back(Pair(a, b)); // big, small
    }

    if (input.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = input.back();
    }
}

/*
    step 02 in the algorithm : build the main chain and the pending chain from the sorted pairs
*/
void SortingHelpers::buildChainsFromPairs(std::deque<Pair>& pairs,
                                        std::deque<int>& mainChain,
                                        std::deque<int>& pending)
{
    pending.clear();
    mainChain.clear();

    // extract big values
    std::deque<int> bigList;
    for (std::size_t i = 0; i < pairs.size(); ++i)
        bigList.push_back(pairs[i].big);

    // sort big values recursively
    std::deque<int> sortedBig = mergeInsertSortRecursive(bigList);

    // rebuild pairs order based on sorted big
    std::deque<Pair> sortedPairs;
    std::deque<bool> used(pairs.size(), false);

    for (std::size_t i = 0; i < sortedBig.size(); ++i)
    {
        for (std::size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used[j] && pairs[j].big == sortedBig[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }

    // build chains
    for (std::size_t i = 0; i < sortedPairs.size(); ++i)
    {
        mainChain.push_back(sortedPairs[i].big);
        pending.push_back(sortedPairs[i].small);
    }
}

/*
    sort the pairs by the big value "recursive sorting" used by step 02
*/
std::deque<int> SortingHelpers::mergeInsertSortRecursive(const std::deque<int>& chain)
{
    if (chain.size() <= 1)
        return chain;

    std::size_t mid = chain.size() / 2;
    std::deque<int> left(chain.begin(), chain.begin() + mid);
    std::deque<int> right(chain.begin() + mid, chain.end());

    left = mergeInsertSortRecursive(left);
    right = mergeInsertSortRecursive(right);

    std::deque<int> merged;

    std::size_t i = 0;
    std::size_t j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            merged.push_back(left[i++]);
        else
            merged.push_back(right[j++]);
    }

    while (i < left.size())
        merged.push_back(left[i++]);
    while (j < right.size())
        merged.push_back(right[j++]);

    return merged;
}

/*
    step 03 in the algorithm : insert the pending chain into the main chain using the Jacobsthal sequence "binary sorting"
*/
void SortingHelpers::insertPending(std::deque<int>& mainChain,
                                const std::deque<int>& pending)
{
    if (pending.empty())
        return;

    std::deque<int>::iterator pos =
        std::lower_bound(mainChain.begin(), mainChain.end(), pending[0]);
    mainChain.insert(pos, pending[0]);

    std::size_t inserted = 1;
    std::size_t n = pending.size();

    // Jacobsthal-like growth
    std::size_t prev = 1;
    std::size_t curr = 3;

    while (inserted < n)
    {
        std::size_t start = std::min(curr, n);

        // insert in reverse order inside the block
        for (std::size_t i = start; i > prev && inserted < n; --i)
        {
            std::size_t idx = i - 1;

            if (idx == 0)
                continue; // already inserted

            std::deque<int>::iterator pos =
                std::lower_bound(mainChain.begin(), mainChain.end(), pending[idx]);
            
            mainChain.insert(pos, pending[idx]);
            inserted++;
        }

        // next Jacobsthal numbers (approx pattern: 1, 3, 5, 11...)
        std::size_t next = curr + prev * 2;
        prev = curr;
        curr = next;
    }
}