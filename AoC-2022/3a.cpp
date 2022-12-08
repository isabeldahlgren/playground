#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("3.txt");
    string line;

    int total = 0;
    while (getline(inFile, line))
    {
        // Splitting lines
        int length = line.length();
        string first = line.substr(0, length / 2);
        string second = line.substr(length / 2, length);

        sort(first.begin(), first.end());
        sort(second.begin(), second.end());

        // Finding intersection
        string intersection;
        set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(intersection));

        // Adding priority
        char ch = intersection[0];
        if (islower(ch))
        {
            total += (int)ch - 96;
        }
        else if (isupper(ch))
        {
            total += (int)ch - 38;
        }
    }
    cout << total << endl;
}