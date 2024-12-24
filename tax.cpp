#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

int main()
{
start:
    system("cls");
    float salary, tax;
    cout << "Input employee's salary = $";
    cin >> salary;
    if (salary < 1000)
    {
        tax = 150;
    }
    else if (salary <= 2000)
    {
        tax = 150 + 0.05 * (salary - 1000);
    }
    else
    {
        tax = 250 + 0.1 * (salary - 2000);
    }
    cout << "==================================" << endl;
    cout << "First salary = $" << salary << endl;
    cout << "Tax = $" << tax << endl;
    salary -= tax;
    cout << "Last salary = $" << salary << endl;
    cout << "Press any key to find employee's tax again : ";
    getch();
    goto start;
    return 0;
}