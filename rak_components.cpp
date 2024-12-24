#include <iostream>
#include <fstream>
using namespace std;

struct Mobile
{
    float usd = 0, riel = 0, in, out;
    int choose;
    string acc_name;
    void account()
    {
        cout << "=============================" << endl;
        cout << "USD account = $" << usd << endl;
        cout << "KH account = R" << riel << endl;
        cout << "=============================" << endl;
    }
    void deposit()
    {
        cout << "1. USD account" << endl;
        cout << "2. KH account" << endl;
        cout << "3. Choose = ";
        cin >> choose;
        if (choose == 1)
        {
            cout << "Deposit = $";
            cin >> in;
            usd += in;
            cout << in << "$ is deposited." << endl;
            account();
        }
        else if (choose == 2)
        {
            cout << "Deposit = R";
            cin >> in;
            riel += in;
            cout << in << "R is deposited." << endl;
            account();
        }
        else
        {
            cout << "Error." << endl;
        }
    }
    void withdraw()
    {
        cout << "1. USD account" << endl;
        cout << "2. KH account" << endl;
        cout << "3. Choose = ";
        cin >> choose;
        if (choose == 1)
        {
            cout << "Withdraw = $";
            cin >> out;
            if (out > usd)
            {
                cout << "Not enough money." << endl;
            }
            else
            {
                usd -= out;
                cout << "$ is withdrawed." << endl;
            }
            account();
        }
        else if (choose == 2)
        {
            cout << "Withdraw = R";
            cin >> out;
            if (out > riel)
            {
                cout << "Not enough money." << endl;
            }
            else
            {
                riel -= out;
            }
            account();
        }
        else
        {
            cout << "Error." << endl;
        }
    }
    void transfer()
    {
        cout << "1. Transfer to your own account" << endl;
        cout << "2. Transfer to another account" << endl;
        cout << "Choose = ";
        cin >> choose;
        if (choose == 1)
        {
            cout << "1. USD => KH" << endl;
            cout << "2. KH => USD" << endl;
            cout << "Choose = ";
            cin >> choose;
            if (choose == 1)
            {
                cout << "Transfer = $";
                cin >> out;
                if (out > usd)
                {
                    cout << "Not enough money." << endl;
                }
                else
                {
                    usd -= out;
                    riel += out * 4000;
                    cout << out << "$ is transfered to KH account" << endl;
                }
                account();
            }
            else if (choose == 2)
            {
                cout << "Transfer = R";
                cin >> out;
                if (out > riel)
                {
                    cout << "Not enough money." << endl;
                }
                else
                {
                    riel -= out;
                    usd += out / 4000;
                    cout << out << "R is transfered to USD account." << endl;
                }
                account();
            }
            else
            {
                cout << "Error." << endl;
            }
        }
        else if (choose == 2)
        {
            cout << "Enter account that you want to transfer to(Account Name) = ";
            cin >> acc_name;
            cout << "1. USD account" << endl;
            cout << "2. KH account" << endl;
            cout << "Choose account = ";
            cin >> choose;
            if (choose == 1)
            {
                cout << "Transfer = $";
                cin >> out;
                if (out > usd)
                {
                    cout << "Not enough money." << endl;
                }
                else
                {
                    usd -= out;
                    cout << out << "$ is transfered to " << acc_name << endl;
                }
                account();
            }
            else if (choose == 2)
            {
                cout << "Transfer = R";
                cin >> out;
                if (out > riel)
                {
                    cout << "Not enough money." << endl;
                }
                else
                {
                    riel -= out;
                    cout << out << "R is transfered to " << acc_name << endl;
                }
                account();
            }
            else
            {
                cout << "Error." << endl;
            }
        }
        else
        {
            cout << "Error." << endl;
        }
    }
};
// case 3:
//     do
//     {
//         cout << "1. Account" << endl;
//         cout << "2. Deposit" << endl;
//         cout << "3. Withdraw" << endl;
//         cout << "4. Transfer" << endl;
//         cout << "5. Exit" << endl;
//         cout << "Choose = ";
//         cin >> option;
//         switch (option)
//         {
//         case 1:
//             acc.account();
//             break;
//         case 2:
//             acc.deposit();
//             break;
//         case 3:
//             acc.withdraw();
//             break;
//         case 4:
//             acc.transfer();
//             break;
//         case 5:
//             break;
//         default:
//             cout << "Error." << endl;
//             break;
//         }
//     } while (option != 5);
//     break;
int main()
{
    system("cls");
    return 0;
}