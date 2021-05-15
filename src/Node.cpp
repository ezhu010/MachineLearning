#include "../header/Node.h"

Node::Node()
{
    this->parent = nullptr;
    this->accuracy = rand() % 100;
    this->children = {};
    this->features = {};
}

void Node::setAccuracy()
{
    accuracy = rand() % 100;
}

double Node::getAccuracy()
{
    return accuracy;
}

std::set<int> Node::getFeatures()
{
    return this->features;
}

Node *Node::createChildren(int featureNumber)
{
    Node *child = new Node();
    child->features = this->features;
    child->features.insert(featureNumber);
    child->parent = this;
    this->children.insert(child);
    return child;
}