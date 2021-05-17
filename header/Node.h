#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <set>
class Node
{
public:
    Node();
    Node(int range);
    double getAccuracy();
    void setAccuracy();
    Node *createChildren(int featureNumber);
    Node *removeChildren(int featureNumber);
    std::set<int> getFeatures();
    std::set<Node *> getChildren() { return children; }
    void printFeatures();
    Node *parent;

private:
    std::set<Node *> children;
    double accuracy;
    std::set<int> features;
};
#endif