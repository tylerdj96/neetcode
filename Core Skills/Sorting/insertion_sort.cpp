#include <iostream>
#include <vector>
using namespace std;

class Pair
{
public:
    int key;
    string value;

    Pair(int key, string value) : key(key), value(value) {}
};

class Solution
{
public:
    vector<vector<Pair>> insertionSort(vector<Pair> &pairs)
    {
        vector<vector<Pair>> sortedPairs = {};
        for (int i = 0; i < pairs.size(); i++)
        {
            sortPair(pairs, pairs.at(i), i);
            sortedPairs.push_back(pairs);
        }

        return sortedPairs;
    }

    void sortPair(vector<Pair> &pairs, Pair &pairToSort, int index)
    {
        if (index == 0)
        {
            return;
        }

        int itr = index;
        Pair currentPair = Pair(pairToSort.key, pairToSort.value);

        while (index > 0)
        {
            Pair pairTotheLeft = Pair(pairs.at(index - 1).key, pairs.at(index - 1).value);
            if (pairTotheLeft.key > currentPair.key)
            {
                pairs[index] = pairTotheLeft;
                index--;
            }
            else
            {
                break;
            }
        }

        pairs[index] = currentPair;
    }
};
