#include "../header/GreedySearch.h"

struct customCompareAccuracy
{
    bool operator()(Node *lhs, Node *rhs)
    {
        return (lhs->getAccuracy() < rhs->getAccuracy());
    }
};

GreedySearch::GreedySearch(int featureCount, Validator *validator, Classifier *classifier)
{
    this->featureCount = featureCount;
    this->validator = validator;
    this->classifier = classifier;
    this->root = new Node(validator, classifier);
    this->backRoot = new Node(featureCount, validator, classifier);
    this->exploredFeatures = {};
    this->root->setAccuracy();
    this->backRoot->setAccuracy();
}

Validator *GreedySearch::getValidator()
{
    return this->validator;
}

Classifier *GreedySearch::getClassifier()
{
    return this->classifier;
}

// GreedySearch::~GreedySearch()
// {

//     delete root;
//     delete backRoot;
// }

void GreedySearch::addFeatureSet(std::set<int> features)
{
    this->exploredFeatures.insert(features);
}

bool GreedySearch::featureSetExists(std::set<int> features) // { {1,2}, {1,3}  } check if {1,2}
{
    if (this->exploredFeatures.count(features))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void GreedySearch::forwardSearch()
{
    std::priority_queue<Node *, std::vector<Node *>, customCompareAccuracy> q;
    q.push(root);
    // std::cout << "Using no features and \"random\" evaluation, I get an accuracy of " << root->getAccuracy() * 100 << '%' << std::endl;
    // std::cout << "\nBeginning Forward Search.\n"
    //           << std::endl;
    while (!q.empty())
    {
        Node *temp = q.top();
        // std::cout << "\nFeature set ";
        // temp->printFeatures();
        // std::cout << " was best, accuracy is " << temp->getAccuracy() * 100 << "%" << std::endl;
        q.pop();
        if (q.top()->getFeatures().size() == this->featureCount)
        {
            std::cout << "The best feature subset is ";
            temp->printFeatures();
            std::cout << " with an accuracy of " << temp->getAccuracy() * 100 << "%" << std::endl;
            return; // reached bottom of tree
        }
        for (int i = 1; i <= this->featureCount; i++)
        {
            std::set<int> tmpSet = temp->getFeatures();
            tmpSet.insert(i);
            if (this->featureSetExists(tmpSet))
            {
                if (i == featureCount)
                {
                    bool allLower = true;
                    for (auto it : temp->getChildren())
                    {
                        if (it->getAccuracy() > temp->getAccuracy())
                        {
                            allLower = false;
                        }
                    }
                    if (allLower)
                    {
                        std::cout << "The best feature subset is ";
                        temp->printFeatures();
                        std::cout << " with an accuracy of " << temp->getAccuracy() * 100 << "%" << std::endl;
                        return; // accuracy has decreased
                    }
                }
                continue;
            }
            else
            {
                this->addFeatureSet(tmpSet);
                Node *newNode = temp->createChildren(i, validator, classifier);

                std::cout << "Using feature(s) ";
                newNode->printFeatures();
                std::cout << " accuracy is " << newNode->getAccuracy() * 100 << '%' << std::endl;
                if (newNode->getAccuracy() >= temp->getAccuracy())
                {
                    q.push(newNode);
                }
                else
                {
                    //std::cout << "TESTING i = " << i << std::endl;
                    if (i == featureCount)
                    {
                        //std::cout << "HERE\n";
                        bool allLower = true;
                        for (auto it : temp->getChildren())
                        {
                            if (it->getAccuracy() > temp->getAccuracy())
                            {
                                allLower = false;
                            }
                        }
                        if (allLower)
                        {
                            std::cout << "The best feature subset is ";
                            temp->printFeatures();
                            std::cout << " with an accuracy of " << temp->getAccuracy() * 100 << "%" << std::endl;
                            return; // accuracy has decreased
                        }
                    }
                }
            }
        }
    }
}

void GreedySearch::backwardSearch()
{

    std::priority_queue<Node *, std::vector<Node *>, customCompareAccuracy> q;
    q.push(backRoot);
    // std::cout << "Using all features and \"random\" evaluation, I get an accuracy of " << backRoot->getAccuracy() * 100 << '%' << std::endl;
    // std::cout << "\nBeginning Backward Search.\n"
    //           << std::endl;
    while (!q.empty())
    {
        Node *temp = q.top();
        // std::cout << "\nFeature set ";
        // temp->printFeatures();
        // std::cout << " was best, accuracy is " << temp->getAccuracy() * 100 << "%" << std::endl;
        q.pop();
        if (q.top()->getFeatures().empty())
        {
            std::cout << "The best feature subset is ";
            temp->printFeatures();
            std::cout << " with an accuracy of " << temp->getAccuracy() * 100 << "%" << std::endl;
            return; // reached bottom of tree
        }
        for (int i = 1; i <= this->featureCount; i++)
        {
            std::set<int> tmpSet = temp->getFeatures();
            if (tmpSet.count(i))
            {
                tmpSet.erase(i);
            }
            if (this->featureSetExists(tmpSet))
            {
                if (i == featureCount)
                {
                    std::cout << "HERE\n";
                    bool allLower = true;
                    for (auto it : temp->getChildren())
                    {
                        if (it->getAccuracy() > temp->getAccuracy())
                        {
                            allLower = false;
                        }
                    }
                    if (allLower)
                    {
                        std::cout << "The best feature subset is ";
                        temp->printFeatures();
                        std::cout << " with an accuracy of " << temp->getAccuracy() * 100 << "%" << std::endl;
                        return; // accuracy has decreased
                    }
                }
                continue;
            }
            else
            {
                this->addFeatureSet(tmpSet);
                Node *newNode = temp->removeChildren(i, validator, classifier);
                std::cout << "Using feature(s) ";
                newNode->printFeatures();
                std::cout << " accuracy is " << newNode->getAccuracy() * 100 << '%' << std::endl;
                if (newNode->getAccuracy() >= temp->getAccuracy())
                {
                    q.push(newNode);
                }
                else
                {
                    //std::cout << "TESTING i = " << i << std::endl;
                    if (i == featureCount)
                    {
                        //std::cout << "HERE\n";
                        bool allLower = true;
                        for (auto it : temp->getChildren())
                        {
                            if (it->getAccuracy() > temp->getAccuracy())
                            {
                                allLower = false;
                            }
                        }
                        if (allLower)
                        {
                            std::cout << "The best feature subset is ";
                            temp->printFeatures();
                            std::cout << " with an accuracy of " << temp->getAccuracy() * 100 << "%" << std::endl;
                            return; // accuracy has decreased
                        }
                    }
                }
            }
        }
    }
}