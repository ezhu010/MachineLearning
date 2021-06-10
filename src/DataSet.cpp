#include "../header/DataSet.h"

DataSet::DataSet() {}
DataSet::DataSet(std::string filename)
{
    this->filename = filename;
    this->loadDataSet();
}

// DataSet::~DataSet()
// {
//     for (int i = 0; i < instances.size(); i++)
//         delete instances[i];
// }

std::vector<Instance *> DataSet::getInstances()
{
    return instances;
}

void DataSet::addInstance(Instance *ins)
{
    this->instances.push_back(ins);
}

void DataSet::loadDataSet()
{
    std::ifstream data(filename);
    std::string line;
    while (std::getline(data, line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<std::string> parsedRow;
        while (std::getline(lineStream, cell, ' '))
        {
            parsedRow.push_back(cell);
        }
        parsedCsv.push_back(parsedRow);
    }

    int id = 1;
    for (int i = 0; i < parsedCsv.size(); i++)
    {
        Instance *temp = new Instance();
        for (int j = 0; j < parsedCsv[i].size(); j++)
        {
            if (j != 0) // shift + tab to fix the dataset. Make sure there is no space in the beginning of the line.
            {
                temp->feature_vals.push_back(stod(parsedCsv[i][j]));
            }
            else
            {
                temp->class_label = stod(parsedCsv[i][j]);
                temp->id = id;
                id++;
            }
        }
        instances.push_back(temp);
    }

    normalizeDataSet();
    // for (int i = 0; i < parsedCsv.size(); i++)
    // {
    //     for (int j = 0; j < parsedCsv[i].size() - 1; j++)
    //     {
    //         cout << instances[i]->feature_vals[j] << ' ';
    //     }
    //     cout << endl;
    // }
}

void DataSet::normalizeDataSet()
{

    int numCol = parsedCsv[0].size(); // includes class label as well --> num of features is numCol - 1
    int numRow = instances.size();
    vector<double> avg;
    vector<double> stdDiv;

    // average
    for (int i = 0; i < numCol - 1; i++)
    {
        double sum = 0.0;
        for (int j = 0; j < numRow; j++)
        {
            sum += instances[j]->feature_vals[i];
        }
        avg.push_back(sum / (double)numRow);
    }

    // std div
    for (int i = 0; i < numCol - 1; i++)
    {
        double partial_sum = 0.0;
        double avg_of_col = avg[i];

        for (int j = 0; j < numRow; j++)
        {
            double x = instances[j]->feature_vals[i];
            partial_sum += pow((x - avg_of_col), 2.0);
        }
        double variance = partial_sum / (double)(numRow - 1);
        double std_div = sqrt(variance);
        stdDiv.push_back(std_div);
    }

    // acutal normalization -> x =  (x - mean(x))/ std(x)
    for (int i = 0; i < numCol - 1; i++)
    {
        for (int j = 0; j < numRow; j++)
        {
            instances[j]->feature_vals[i] = (instances[j]->feature_vals[i] - avg[i]) / stdDiv[i];
        }
    }
}

DataSet *DataSet::trimDataSet(const set<int> &feature_subset)
{

    DataSet *res = new DataSet();

    for (int i = 0; i < this->instances.size(); i++)
    {
        Instance *temp = new Instance();
        for (int j = 0; j < parsedCsv.at(i).size() - 1; j++)
        {
            if (find(feature_subset.begin(), feature_subset.end(), j + 1) != feature_subset.end())
            {
                temp->feature_vals.push_back(this->instances[i]->feature_vals[j]);
            }
        }

        temp->class_label = this->instances[i]->class_label;
        temp->id = this->instances[i]->id;
        res->instances.push_back(temp);
    }
    //cout << parsedCsv.size() << endl;
    return res;
}
