#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("2.txt");
    string line;
    int score = 0;
    char elf_move, my_move;
    while (getline(inFile, line))
    {
        elf_move = line.c_str()[0];
        my_move = line.c_str()[2];
        switch (my_move)
        {
        case 'X':
            score += 1;
            break;
        case 'Y':
            score += 2;
            break;
        case 'Z':
            score += 3;
            break;
        }
        if (my_move == 'X' && elf_move == 'A'
        || my_move == 'Y' && elf_move == 'B'
        || my_move == 'Z' && elf_move == 'C')
        {
            score += 3;
        }
        else if (my_move == 'Z' && elf_move == 'B'
        || my_move == 'Y' && elf_move == 'A'
        || my_move == 'X' && elf_move == 'C')
        {
            score += 6;
        }
    }
    cout << score << endl;
}