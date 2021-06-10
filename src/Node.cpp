#include "../header/Node.h"
#include "../header/Validator.h"
#include "../header/NNClassifier.h"

Node::Node()
{
    this->parent = nullptr;
    this->accuracy = 0.0;
    this->children = {};
    this->features = {};
}

Node::Node(Validator *validator, Classifier *classifier)
{
    this->parent = nullptr;
    this->children = {};
    this->features = {};
    this->validator = validator;
    this->classifier = classifier;
    this->accuracy = 0.0;
}

// Node::~Node()
// {
//     for (auto s : children)
//         delete s;

// }

Node::Node(int range, Validator *validator, Classifier *classifier)
{
    this->parent = nullptr;
    this->children = {};
    this->features = {};
    for (int i = 1; i <= range; i++)
        this->features.insert(i);
    this->validator = validator;
    this->classifier = classifier;
    this->accuracy = 0.0;
}

void Node::setAccuracy()
{
    accuracy = this->validator->getAccuracy(this->features, this->classifier);
}

double Node::getAccuracy()
{
    return accuracy;
}

std::set<int> Node::getFeatures()
{
    return this->features;
}

Node *Node::createChildren(int featureNumber, Validator *validator, Classifier *classifier)
{
    Node *child = new Node(validator, classifier);
    child->features = this->features;
    child->features.insert(featureNumber);
    child->parent = this;
    this->children.insert(child);
    child->accuracy = child->validator->getAccuracy(child->features, child->classifier);
    return child;
}

Node *Node::removeChildren(int featureNumber, Validator *Validator, Classifier *classifier)
{
    Node *child = new Node(validator, classifier);
    child->features = this->features;
    child->features.erase(featureNumber);
    child->parent = this;
    this->children.insert(child);
    child->accuracy = child->validator->getAccuracy(child->features, child->classifier);
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