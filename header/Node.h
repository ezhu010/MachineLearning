#ifndef __NODE_H__
#define __NODE_H__
#include <random>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <set>
class Node
{
public:
    Node();
    double getAccuracy();
    void setAccuracy();
    Node *createChildren(int featureNumber);
    std::set<int> getFeatures();

private:
    Node *parent;
    std::set<Node *> children;
    double accuracy;
    std::set<int> features;
};
#endif