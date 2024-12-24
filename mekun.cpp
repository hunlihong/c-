#include <iostream>
using namespace std;

int main()
{
    system("cls");
    // int n;
    // cout << "Input n = ";
    // cin >> n;
    // int i = 1;
    // do
    // {
    //     cout << n << " x " << i << " = " << n * i << endl;
    //     i++;
    // } while (i <= 10);

    int n;
    cout << "Input n = ";
    cin >> n;
    int i = 1;
    cout << "Odd = ";
    do
    {
        if (i % 2 != 0)
        {
            cout << i << " ";
        }
        i++;
    } while (i <= n);
    i = 1;
    cout << endl;
    cout << "Even = ";
    do
    {
        if (i % 2 == 0)
        {
            cout << i << " ";
        }
        i++;
    } while (i <= n);
    return 0;
}