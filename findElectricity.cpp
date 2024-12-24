#include <iostream>
#include <iomanip>
using namespace std;

void pressEnter()
{
    cin.get();
    cin.get();
}
int main()
{
start:
    system("cls");
    float preValue, newValue, charge;
    cout << "Enter previous electricity = ";
    cin >> preValue;
    cout << "Enter current electricity = ";
    cin >> newValue;
    if (newValue < preValue)
    {
        cout << "current electricity must be equal or greater than the previos one!" << endl;
        cout << "Press Enter to go again : ";
        pressEnter();
        goto start;
    }
    cout << "====================================" << endl;
    float electricity = newValue - preValue;
    cout << "Electricity = " << electricity << endl;
    if (electricity < 100)
    {
        charge = electricity * 600;
    }
    else
    {
        if (electricity <= 200)
        {
            charge = (100 * 600) + (electricity - 100) * 800;
        }
        else
        {
            charge = (100 * 600) + (100 * 800) + (electricity - 200) * 1000;
        }
    }
    cout << "Charge = R" << charge << endl;
    cout << "Press Enter to go again : ";
    pressEnter();
    goto start;
    return 0;
}