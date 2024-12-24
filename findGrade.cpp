#include <iostream>
using namespace std;

int main()
{
    system("cls");
    float score[3], total = 0;
    for (int i = 0; i < 3; i++)
    {
        cout << "Input score=";
        cin >> score[i];
        total += score[i];
    }
    if (total >= 90)
        cout << "Grade A";
    else
    {
        if (total >= 70)
            cout << "Grade B";
        else
        {
            if (total >= 50)
                cout << "Grade C";
            else
                cout << "Grade F";
        }
    }
    return 0;
}