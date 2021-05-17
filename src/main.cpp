#include "../header/Node.h"
#include "../header/GreedySearch.h"
#include <iostream>
using namespace std;
int main()
{
    srand(time(0));
    cout << "Welcome to XYZCoders Feature Selection Algorithm" << endl;
    cout << "Please enter the total number of features: ";
    int featureCount;
    cin >> featureCount;
    cout << "Type the number of the algorithm you want to run." << endl;
    cout << "1. Foward Selection\n2. Backward Elimination\n3. Bertie's Special Algorithm\n";
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
    cout << "END OF ALGORITHM" << endl;
}