#include "../header/Node.h"
#include "../header/GreedySearch.h"
#include "../header/DataSet.h"
#include "../header/NNClassifier.h"
#include "../header/Validator.h"
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <ctime>
#include <ratio>

//  https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp/
using namespace std;

void print_vec(const vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == vec.size() - 1)
            cout << vec[i];
        else
            cout << vec[i] << ", ";
    }
}

int main(int argc, char *argv[])
{
    auto start = chrono::high_resolution_clock::now();
    DataSet *data_set = new DataSet(argv[1]);
    Classifier *classifier = new NNClassifier();
    classifier->train(data_set);
    Validator *validator = new Validator();
    cout << "Enter the Number of features" << endl;
    int n;
    cin >> n;

    cout << "Enter the features you want to get the accuracy of:";
    vector<int> feature_set;
    while (n--)
    {
        int temp;
        cin >> temp;
        feature_set.push_back(temp);
    }
    cout << "The accuracy of using features: {";
    print_vec(feature_set);
    cout << '}' << endl;
    cout << validator->getAccuracy(feature_set, classifier) << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "The algorithm took " << duration.count() / 1000000.0 << " seconds" << endl;

    /*
    srand(time(0));
    cout << "Welcome to XYZCoders Feature Selection Algorithm" << endl;
    cout << "Please enter the total number of features: ";
    int featureCount;
    cin >> featureCount;
    cout << "Type the number of the algorithm you want to run." << endl;
    cout << "1. Forward Selection\n2. Backward Elimination\n3. Bertie's Special Algorithm\n";
    int method;
    cin >> method;
    GreedySearch *greedy = new GreedySearch(featureCount);

    switch (method)
    {
    case 1:
        greedy->forwardSearch();
        break;
    case 2:
        greedy->backwardSearch();
        break;
    }
    cout << "END OF ALGORITHM" << endl; **/
}