#include "../header/Node.h"
#include "../header/GreedySearch.h"
#include "../header/DataSet.h"
#include "../header/NNClassifier.h"
#include <iostream>
#include <stdio.h>

//  https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp/
using namespace std;
int main(int argc, char *argv[])
{
    DataSet *data_set = new DataSet(argv[1]);
    data_set->normalizeDataSet();
    NNClassifier *classifier = new NNClassifier();
    classifier->train(data_set);

    /**
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