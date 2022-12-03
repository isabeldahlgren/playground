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
    char elf_move, outcome;
    while (getline(inFile, line))
    {
        elf_move = line.c_str()[0];
        outcome = line.c_str()[2];

        // If you win
        if (outcome == 'Z')
        {
            score += 6;
            if (elf_move == 'A')
            {
                score += 2;
            }
            else if (elf_move == 'B')
            {
                score += 3;
            }
            else if (elf_move == 'C')
            {
                score += 1;
            }
        }
        // If it's a draw
        else if (outcome == 'Y')
        {
            score += 3;
            if (elf_move == 'A')
            {
                score += 1;
            }
            else if (elf_move == 'B')
            {
                score += 2;
            }
            else if (elf_move == 'C')
            {
                score += 3;
            }
        }
        // If you loose
        else
        {
            if (elf_move == 'A')
            {
                score += 3;
            }
            else if (elf_move == 'B')
            {
                score += 1;
            }
            else if (elf_move == 'C')
            {
                score += 2;
            }
        }
    }
    cout << score << endl;
}