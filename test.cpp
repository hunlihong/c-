#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int number1[] = {1, 2, 3};
    int number2[] = {1, 2, 3};
    bool compare;
    for (int i = 0; i < 3; i++)
    {
        if (number1[i] == number2[i])
        {
            compare = true;
        }
        else
        {
            compare = false;
        }
    }
    cout << "Compare = " << compare << endl;
    return 0;
}