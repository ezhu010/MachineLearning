#ifndef __CLASSIFIER__
#define __CLASSIFIER__

#include "DataSet.h"

class Classifier
{
public:
    Classifier() { this->data_set = nullptr; }
    DataSet *getDataSet() { return data_set; }
    virtual void train(DataSet *) = 0;
    virtual int test(Instance *) = 0;
    DataSet *data_set;

protected:
};

#endif