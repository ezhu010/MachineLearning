#include "../header/Node.h"

Node::Node()
{
    this->parent = nullptr;
    this->accuracy = ((double)rand() / RAND_MAX) * 100;
    this->children = {};
    this->features = {};
}

Node::Node(int range)
{
    this->parent = nullptr;
    this->accuracy = rand() % 100;
    this->children = {};
    this->features = {};
    for (int i = 1; i <= range; i++)
        this->features.insert(i);
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

Node *Node::removeChildren(int featureNumber)
{
    Node *child = new Node();
    child->features = this->features;
    child->features.erase(featureNumber);
    child->parent = this;
    this->children.insert(child);
    return child;
}

// { 1, 2, 3, 4}
void Node::printFeatures()
{
    std::cout << '{';
    int count = 0;
    for (auto x : features)
    {
        if (count == features.size() - 1)
            std::cout << x;
        else
        {
            std::cout << x << ", ";
        }
        count++;
    }
    std::cout << '}';
}