#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;
int function(int x, int y)
{
    return x + y;
}
long function(long x, long y)
{
    return x - y;
}
float function(float x, float y)
{
    return x * y;
}
double function(double x, double y)
{
    return x / y;
}

int main()
{
start:
    system("cls");
    int x, y;
    int op;
    cout << "1. -     2. *" << endl;
    cout << "3. +     4. /" << endl;
    cout << "Chose =";
    cin >> op;
    switch (op)
    {
    case 1:
        cout << "Input value 1 =";
        cin >> x;
        cout << "Input value 2 =";
        cin >> y;
        cout << "Answer = " << function((long)x, (long)y);
        break;
    case 2:
        cout << "Input value 1 =";
        cin >> x;
        cout << "Input value 2 =";
        cin >> y;
        cout << "Answer = " << function((float)x, (float)y);
        break;
    case 3:
        cout << "Input value 1 =";
        cin >> x;
        cout << "Input value 2 =";
        cin >> y;
        cout << "Answer = " << function((int)x, (int)y);
        break;
    case 4:
        cout << "Input value 1 =";
        cin >> x;
        cout << "Input value 2 =";
        cin >> y;
        cout << "Answer = " << function((double)x, (double)y);
        break;
    }
    cout << endl;
    cout << "=================================" << endl;
    cout << "Type anything to go again : ";
    getch();
    goto start;
    return 0;
}