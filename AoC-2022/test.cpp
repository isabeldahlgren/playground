#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    cout << fixed << setprecision(2);
    float gpaTot = 0, gpa, clasNum;
    int creds;
    string clas, cont = "Yes", grade;

    while (cont == "Yes")
    {
        cout << "Enter a course name: ";
        getline(cin, clas);
        cout << clas << endl
             << "Enter number of credits: ";
        cin >> creds;
        cout << creds << endl
             << "Enter your grade (A, B, C, D, F): ";
        cin >> grade;
        cout << grade << endl
             << "Continue ('Yes' or 'No')? ";
        cin >> cont;
        cout << cont << endl;
        cin.ignore();
    }
}