#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
start:
    system("cls");
    int i = 1, total = 0, n;
    cout << "Input n = ";
    cin >> n;
    while (i <= n)
    {
        if (i % 2 == 0)
        {
            total += i;
        }
        i++;
    }
    i = 1;
    cout << "Even numbers : ";
    while (i <= n)
    {
        if (i % 2 == 0)
        {
            cout << i;
            if (n % 2 == 0)
            {
                if (i != n)
                {
                    cout << " + ";
                }
            }
            else
            {
                if (i != n - 1)
                {
                    cout << " + ";
                }
            }
        }
        i++;
    }
    cout << " = " << total << endl;
    getch();
    goto start;
    return 0;
}