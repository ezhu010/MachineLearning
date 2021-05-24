#include <bits/stdc++.h>
using namespace std;

std::vector<std::vector<std::string>> parsedCsv;

void parseCSV(string filename)
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
};

int main(int argc, char *argv[])
{
    parseCSV(argv[1]);

    for (int i = 0; i < parsedCsv.size(); i++)
    {
        for (int j = 0; j < parsedCsv[i].size(); j++)
        {
            cout << stod(parsedCsv[i][j]) << ',';
        }
        cout << endl;
    }
    return 0;
}