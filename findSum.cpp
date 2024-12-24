#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
start:
    system("cls");
    int n, i = 1, f = 1, result = 0;
    cout << "Input n = ";
    cin >> n;
    cout << "--------------------------" << endl;
    cout << "Sn = ";
    while (i <= n)
    {
        cout << i << "!";
        if (i <= n - 1)
            cout << " + ";
        f *= i;
        i++;
        result += f;
    };
    cout << endl;
    cout << "Result = " << result << endl;
    getch();
    goto start;
    return 0;
}