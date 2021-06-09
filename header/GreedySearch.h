#ifndef __GREEDY_SEARCH__
#define __GREEDY_SEARCH__
#include "Node.h"
#include <queue>
#include <iostream>
#include "Validator.h"
#include "NNClassifier.h"
class GreedySearch
{
public:
    GreedySearch(int featureCount, Validator *newValidator, Classifier *newClassifier);
    ~GreedySearch();
    void addFeatureSet(std::set<int> features);
    bool featureSetExists(std::set<int> features);
    void forwardSearch();
    void backwardSearch();
    Validator *getValidator();
    Classifier *getClassifier();

private:
    Node *root;
    Node *backRoot;
    std::set<std::set<int>> exploredFeatures;
    int featureCount;
    Validator *validator;
    Classifier *classifier;
};
#endif
