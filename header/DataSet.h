#ifndef __DATA_SET__
#define __DATA_SET__

#include <bits/stdc++.h>
using namespace std;
struct Instance
{
    int id;
    int class_label;
    std::vector<double> feature_vals;
};

class DataSet
{
public:
    DataSet() {}
    ~DataSet();
    DataSet(string filename);
    void loadDataSet();
    void normalizeDataSet();
    std::vector<std::vector<std::string>> parsedCsv;
    std::vector<Instance *> getInstances();
    void addInstance(Instance *);
    DataSet *trimDataSet(const vector<int> &feature_subset);

private:
    string filename;
    std::vector<Instance *> instances;
};
#endif