#include <iostream>
using namespace std;

int main()
{
    system("cls");
    float a, b, c, max, min;
    cout << "Input a=";
    cin >> a;
    cout << "Input b=";
    cin >> b;
    cout << "Input c=";
    cin >> c;
    if (a > b)
    {
        if (a > c)
        {
            max = a;
            if (b > c)
                min = c;
            else
                min = b;
        }
        else
        {
            max = c;
            min = b;
        }
    }
    else
    {
        if (b > c)
        {
            max = b;
            if (a > c)
                min = c;
            else
                min = a;
        }
        else
        {
            max = c;
            min = a;
        }
    }
    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;
    return 0;
}