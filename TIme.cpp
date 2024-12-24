#include <iostream>
using namespace std;

int main()
{
start:
    system("cls");
    int time_in, time_out, charge, money;
    cout << "Input time_in = ";
    cin >> time_in;
    if (time_in < 6)
    {
        cout << "School starts working at 6AM" << endl;
        goto start;
    }
    cout << "Input time_out = ";
    cin >> time_out;
    if (time_out > 24)
    {
        cout << "Error" << endl;
        goto start;
    }
    else
    {
        if (time_in > 12)
        {
            charge = 400;
        }
        else
        {
            if (time_out <= 12)
            {
                charge = 200;
            }
            else
            {
                charge = 400;
            }
        }
        money = (time_out - time_in) * charge;
        cout << "You need to pay = " << money << endl;
    }
}