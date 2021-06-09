#include "../header/Validator.h"

Validator::Validator() {}

double Validator::getAccuracy(const set<int> &feature_subset, Classifier *classifier) // 1 3 7 -> ~89
{
    int counter = 0; // total number of tests
    int success = 0; // successful tests
    if (feature_subset.empty())
    {
        int OnesCounter = 0;
        int TwosCounter = 0;
        DataSet *data = classifier->getDataSet();
        for (int i = 0; i < data->getInstances().size(); i++)
        {
            if (data->getInstances().at(i)->class_label == 1)
                OnesCounter++;
            else
                TwosCounter++;
            counter++;
        }
        success = max(OnesCounter, TwosCounter);
    }
    else
    {
        cout << "TEST ELSE" << endl;

        DataSet *new_trim_data = classifier->getDataSet()->trimDataSet(feature_subset);
        int feature_size = new_trim_data->getInstances().at(0)->feature_vals.size();

        for (int i = 0; i < new_trim_data->getInstances().size(); i++)
        {
            // get rid of the ith row in trimmed data set
            DataSet *row_trimmed_data = rowTrimDataSet(i, new_trim_data);
            // train the new instance with the rest
            Classifier *tmp = new NNClassifier();
            tmp->train(row_trimmed_data);
            int resultOfTest = tmp->test(new_trim_data->getInstances().at(i));
            if (resultOfTest == new_trim_data->getInstances().at(i)->class_label)
                success++;
            counter++;
        }
    }
    double res = 0.0;
    return (double)success / (double)counter;
}

DataSet *Validator::rowTrimDataSet(int skipRow, DataSet *data_set)
{
    DataSet *res = new DataSet();
    for (int i = 0; i < data_set->getInstances().size(); i++)
    {
        if (i != skipRow)
        {
            Instance *temp = new Instance();
            temp->feature_vals = data_set->getInstances().at(i)->feature_vals;
            temp->class_label = data_set->getInstances().at(i)->class_label;
            temp->id = data_set->getInstances().at(i)->id;
            res->addInstance(temp);
        }
    }
    return res;
}
