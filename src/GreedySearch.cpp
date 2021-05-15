#include "../header/GreedySearch.h"

struct customCompareAccuracy
{
    bool operator(Node *lhs, Node *rhs)
    {
        return (lhs->getAccuracy() > rhs->getAccuracy());
    }
}

GreedySearch::GreedySearch()
{
    this->root = new Node();
    this->exploredFeatures = {};
}
void GreedySearch::addFeatureSet(std::set<int> features)
{
    this->exploredFeatures.insert(features);
}
bool GreedySearch::featureSetExists(std::set<int> features) // { {1,2}, {1,3}  } check if {1,2}
{
    if (this->explordFeatures.count(features))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GreedySearch::search()
{
}