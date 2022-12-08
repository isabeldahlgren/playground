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
    bool cont = true;
    while (cont)
    {
        // Find rucksacks of each group
        string rucksacks[3];
        string tmpRucksack;
        for (int i = 0; i < 3; i++)
        {
            if (!getline(inFile, tmpRucksack))
            {
                cont = false;
            }
            // Sorting (to find intersection later)
            sort(tmpRucksack.begin(), tmpRucksack.end());
            rucksacks[i] = tmpRucksack;
        }

        // Find intersection
        string tmpIntersection;
        set_intersection(rucksacks[0].begin(), rucksacks[0].end(),
                         rucksacks[1].begin(), rucksacks[1].end(),
                         back_inserter(tmpIntersection));
        string intersection;
        set_intersection(tmpIntersection.begin(), tmpIntersection.end(),
                         rucksacks[2].begin(), rucksacks[2].end(),
                         back_inserter(intersection));

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