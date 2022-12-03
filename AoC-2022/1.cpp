#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("1.txt");
    string line;

    double tmp = 0;
    double first = 0;
    double second = 0;
    double third = 0;

    while (getline(inFile, line))
    {
        // If new elf
        if (line.empty())
        {
            if (tmp > first)
            {
                third = second;
                second = first;
                first = tmp;
            }
            else if (tmp > second)
            {
                third = second;
                second = tmp;
            }
            else if (tmp > third)
            {
                third = tmp;
            }
            // Reset tmp
            tmp = 0;
        }
        // If same elf, increment
        else
        {
            tmp += stoi(line);
        }
    }
    cout << first << endl;
    cout << first + second + third << endl;
}