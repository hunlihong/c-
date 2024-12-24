#include <iostream>
using namespace std;
int functionadd(int x, int y)
{
    return x - y;
}
double functionadd(double j, double k)
{
    return j * k;
}
int functionadd(int o, int p)
{
    return o + p;
}
int functionadd(int c, int i)
{
    return c / i;
}

int main()
{
    int op;
    int x, y;
    cout << "1. -     2. *" << endl;
    cout << "3. +     4. /" << endl;
    cout << "Chose =" << endl;
    cin >> op;
    switch (op)
    {
    case 1:
        int myNum1 = functionadd(x, y);
        cout << "Total 1 :" << endl;
        cin >> x;
        cout << "Total 2 :" << endl;
        cin >> y;
        cout << "Int : " << myNum1 << "\n";
        break;
    case 2:
        double myNum2 = functionadd(x, y);
        cout << "double :" << myNum2;
        break;
    }

    return 0;
}
