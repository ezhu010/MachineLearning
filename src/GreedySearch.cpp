#include "../header/GreedySearch.h"

struct customCompareAccuracy
{
    bool operator()(Node *lhs, Node *rhs)
    {
        return (lhs->getAccuracy() < rhs->getAccuracy());
    }
};

GreedySearch::GreedySearch(int featureCount)
{
    this->featureCount = featureCount;
    this->root = new Node();
    this->backRoot = new Node(featureCount);
    this->exploredFeatures = {};
}

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
    std::cout << "Using no features and \"random\" evaluation, I get an accuracy of " << root->getAccuracy() << '%' << std::endl;
    std::cout << "\nBeginning Forward Search.\n"
              << std::endl;
    while (!q.empty())
    {
        Node *temp = q.top();
        std::cout << "\nFeature set ";
        temp->printFeatures();
        std::cout << " was best, accuracy is " << temp->getAccuracy() << "%" << std::endl;
        q.pop();
        if (q.top()->getFeatures().size() == this->featureCount)
        {
            std::cout << "The best feature subset is ";
            temp->printFeatures();
            std::cout << " with an accuracy of " << temp->getAccuracy() << "%" << std::endl;
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
                        std::cout << " with an accuracy of " << temp->getAccuracy() << "%" << std::endl;
                        return; // accuracy has decreased
                    }
                }
                continue;
            }
            else
            {
                this->addFeatureSet(tmpSet);
                Node *newNode = temp->createChildren(i);
                std::cout << "Using feature(s) ";
                newNode->printFeatures();
                std::cout << " accuracy is " << newNode->getAccuracy() << '%' << std::endl;
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
                            std::cout << " with an accuracy of " << temp->getAccuracy() << "%" << std::endl;
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
    std::cout << "Using all features and \"random\" evaluation, I get an accuracy of " << backRoot->getAccuracy() << '%' << std::endl;
    std::cout << "\nBeginning Backward Search.\n"
              << std::endl;
    while (!q.empty())
    {
        Node *temp = q.top();
        std::cout << "\nFeature set ";
        temp->printFeatures();
        std::cout << " was best, accuracy is " << temp->getAccuracy() << "%" << std::endl;
        q.pop();
        if (q.top()->getFeatures().empty())
        {
            std::cout << "The best feature subset is ";
            temp->printFeatures();
            std::cout << " with an accuracy of " << temp->getAccuracy() << "%" << std::endl;
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
                        std::cout << " with an accuracy of " << temp->getAccuracy() << "%" << std::endl;
                        return; // accuracy has decreased
                    }
                }
                continue;
            }
            else
            {
                this->addFeatureSet(tmpSet);
                Node *newNode = temp->removeChildren(i);
                std::cout << "Using feature(s) ";
                newNode->printFeatures();
                std::cout << " accuracy is " << newNode->getAccuracy() << '%' << std::endl;
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
                            std::cout << " with an accuracy of " << temp->getAccuracy() << "%" << std::endl;
                            return; // accuracy has decreased
                        }
                    }
                }
            }
        }
    }
}