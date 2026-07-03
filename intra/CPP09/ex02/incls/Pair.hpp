#ifndef PAIR_HPP
#define PAIR_HPP

/*
    Pair struct
    This struct is used to store a pair of integers
    It is used to store the big and small values of the input
    it is for the first sorting step of the merge insert sort algorithm
*/

struct Pair
{
    int big;
    int small;

    Pair();
    Pair(int b, int s);
};

#endif