#ifndef __GREEDY_SEARCH__
#define __GREEDY_SEARCH__
#include "Node.h"
#include <queue>
#include <iostream>
class GreedySearch
{
public:
    GreedySearch(int featureCount);
    void addFeatureSet(std::set<int> features);
    bool featureSetExists(std::set<int> features);
    void forwardSearch();
    void backwardSearch();

private:
    Node *root;
    Node *backRoot;
    std::set<std::set<int>> exploredFeatures;
    int featureCount;
};
#endif
