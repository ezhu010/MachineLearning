#ifndef __VALIDATOR__
#define __VALIDATOR__

#include "NNClassifier.h"
#include "DataSet.h"

class Validator
{
public:
    Validator();
    double getAccuracy(const vector<int> &feature_subset, Classifier *classifier);
    void trimDataSet(const vector<int> &feature_subset, DataSet *data_set);
    DataSet *rowTrimDataSet(int i, DataSet *);

private:
};

#endif