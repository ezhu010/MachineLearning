#ifndef __CLASSIFIER__
#define __CLASSIFIER__

#include "DataSet.h"

class Classifier
{
public:
    Classifier() { this->data_set = nullptr; }
    ~Classifier() {delete data_set; }
    DataSet *getDataSet() { return data_set; }
    virtual void train(DataSet *) = 0;
    virtual int test(Instance *) = 0;

protected:
    DataSet *data_set;
};

#endif