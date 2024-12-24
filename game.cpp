#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

string numbers[10][10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "100"};

void interface()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << right << setw(3) << numbers[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void processing(string player)
{
    for (int i = 0; i < 10; i++)
    {
        if (numbers[i][i] == numbers[i][i + 1] && numbers[i][i + 1] == numbers[i][i + 2] && numbers[i][i + 2] == numbers[i][i + 3] && numbers[i][i + 3] == numbers[i][i + 4])
        {
            cout << player << " is the winner." << endl;
            exit(0);
        }
        else if (numbers[i][i] == numbers[i + 1][i] && numbers[i + 1][i] == numbers[i + 2][i] && numbers[i + 2][i] == numbers[i + 3][i] && numbers[i + 3][i] == numbers[i + 4][i])
        {
            cout << player << " is the winner." << endl;
            exit(0);
        }
        else if (numbers[i][i] == numbers[i + 1][i + 1] && numbers[i + 1][i + 1] == numbers[i + 2][i + 2] && numbers[i + 2][i + 2] == numbers[i + 3][i + 3] && numbers[i + 3][i + 3] == numbers[i + 4][i + 4])
        {
            cout << player << " is the winner." << endl;
            exit(0);
        }
    }
}

int main()
{
    system("cls");
    string nameX, nameO, x, o;
    bool condition = false;
    cout << "==================> Welcome to Tic Tac Toe Gaming <==================" << endl;
    cout << "Enter name of player X : ";
    cin >> nameX;
    cout << "Enter name of player O : ";
    cin >> nameO;
    interface();
playing_process:
chooseX:
    cout << nameX << ", choose a number for X : ";
    cin >> x;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (x == numbers[i][j])
            {
                condition = true;
                numbers[i][j] = "X";
            }
        }
    }
    if (!condition)
    {
        cout << "Number not found!" << endl;
        cout << "Press any key to choose again : " << endl;
        getch();
        goto chooseX;
    }
    condition = false;
    interface();
    processing(nameX);
chooseO:
    cout << nameO << ", choose a number for O : ";
    cin >> o;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (o == numbers[i][j])
            {
                condition = true;
                numbers[i][j] = "O";
            }
        }
    }
    if (!condition)
    {
        cout << "Number not found!" << endl;
        cout << "Press any key to choose again : " << endl;
        getch();
        goto chooseO;
    }
    condition = false;
    interface();
    processing(nameO);
    goto playing_process;
    return 0;
}