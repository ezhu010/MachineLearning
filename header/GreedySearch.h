#ifndef __GREEDY_SEARACH__
#define __GREEDY_SEARCH__
#include "Node.h"

class GreedySeach
{
public:
    GreedySeach();
    void addFeatureSet(std::set<int> features);
    bool featureSetExists(std::set<int> features);
    void search();

private:
    Node *root;
    std::set<std::set<int>> exploredFeatures;
};
#endif
