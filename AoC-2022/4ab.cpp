#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("4.txt");
    string line;
    int containments = 0;
    int overlaps = 0;
    while (getline(inFile, line)) {
        string firstRange = line.substr(0, line.find(','));
        string secondRange = line.substr(line.find(',') + 1);
        int a = stoi(firstRange.substr(0, firstRange.find('-')));
        int b = stoi(firstRange.substr(firstRange.find('-') + 1));
        int c = stoi(secondRange.substr(0, secondRange.find('-')));
        int d = stoi(secondRange.substr(secondRange.find('-') + 1));
        if ((a <= c && b >= d) || (c <= a && d >= b)) {
            containments++;
        }
        if ((c <= a && a <= d) || (a <= c && c <= b)) {
            overlaps++;
        }
    }
    cout << containments << endl;
    cout << overlaps << endl;
}