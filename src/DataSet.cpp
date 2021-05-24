#include "../header/DataSet.h"

DataSet::DataSet(std::string filename)
{
    this->filename = filename;
    this->loadDataSet();
}

std::vector<Instance *> DataSet::getInstances()
{
    return instances;
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
        while (std::getline(lineStream, cell, ','))
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
            if (j < parsedCsv[i].size() - 1)
            {
                temp->feature_vals.push_back(stod(parsedCsv[i][j]));
            }
            if (j == parsedCsv[i].size() - 1)
            {
                temp->class_label = stod(parsedCsv[i][j]);
                temp->id = id;
                id++;
            }
        }
        instances.push_back(temp);
    }
    // for (int i = 0; i < instances.size(); i++)
    // {
    //     for (int j = 0; j < instances[i]->feature_vals.size(); j++)
    //     {
    //         cout << instances[i]->feature_vals[j] << ',';
    //     }
    //     cout << instances[i]->class_label;
    //     cout << endl;
    // }
}

void DataSet::normalizeDataSet()
{
    vector<pair<int, int>> normalize;

    int numCol = parsedCsv[0].size();
    int numRow = parsedCsv.size();
    for (int i = 0; i < numCol - 1; i++)
    {
        double sum = 0;
        double average = 0;
        for (int j = 0; j < numRow; j++)
        {
            sum += stod(parsedCsv[j][i]);
        }
        average = sum / numRow;
        cout << average << endl;
    }
}
