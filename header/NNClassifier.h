#ifndef __NN__CLASSIFIER__
#define __NN__CLASSIFIER__

#include "Classifier.h"

#include <math.h>
#include <float.h>

class NNClassifier : public Classifier
{
public:
    NNClassifier();
    NNClassifier(DataSet *);
    void train(DataSet *);
    int test(Instance *);
    double getEucledianDistance(Instance *, Instance *);

private:
};

#endif