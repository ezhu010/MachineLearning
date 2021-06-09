#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <set>
#include "Validator.h"
#include "NNClassifier.h"
class Node
{
public:
    Node();
    ~Node();
    Node(int range, Validator *validator, Classifier *classifier);
    Node(Validator *validator, Classifier *classifier);
    double getAccuracy();
    void setAccuracy();
    Node *createChildren(int featureNumber, Validator *Validator, Classifier *classifier);
    Node *removeChildren(int featureNumber, Validator *Validator, Classifier *classifier);
    std::set<int> getFeatures();
    std::set<Node *> getChildren() { return children; }
    void printFeatures();
    Node *parent;

private:
    std::set<Node *> children;
    double accuracy;
    std::set<int> features;
    Validator *validator;
    Classifier *classifier;
};
#endif