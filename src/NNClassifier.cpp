#include "../header/NNClassifier.h"

NNClassifier::NNClassifier() : Classifier()
{
}

void NNClassifier::train(DataSet *data_set)
{
    this->data_set = data_set;
}

int NNClassifier::test(Instance *instance)
{
    if (instance == nullptr)
    {
        cout << "Can't test a null instance";
        return -1;
    }

    Instance *closestInstance = nullptr;
    double closestDistance = DBL_MAX;
    for (const auto &i : this->data_set->getInstances())
    {
        double tmpDist = this->getEucledianDistance(instance, i);
        if (tmpDist < closestDistance)
        {
            closestDistance = tmpDist;
            closestInstance = i;
        }
    }

    return closestInstance->class_label;
}

double NNClassifier::getEucledianDistance(Instance *lhs, Instance *rhs)
{
    double res = 0.0;
    int size = lhs->feature_vals.size();
    for (int i = 0; i < size; i++)
    {
        res += pow((lhs->feature_vals[i] - rhs->feature_vals[i]), 2.0);
    }
    res = pow(res, 0.5);
    return res;
}