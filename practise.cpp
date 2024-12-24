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
void processing_0(string player, bool finish)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (numbers[i][j] == numbers[i][j + 1] && numbers[i][j + 1] == numbers[i][j + 2] && numbers[i][j + 2] == numbers[i][j + 3] && numbers[i][j + 3] == numbers[i][j + 4])
            {
                finish = true;
                cout << player << " is the winner." << endl;
                break;
            }
            if (finish == false)
            {
            }
            else if (numbers[i][j] == numbers[i + 1][j] && numbers[i + 1][j] == numbers[i + 2][j] && numbers[i + 2][j] == numbers[i + 3][j] && numbers[i + 3][j] == numbers[i + 4][j])
            {
                cout << player << " is the winner." << endl;
            }
        }
    }
}
// void processing_90(string player)
// {
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             if (numbers[j][j] == numbers[j + 1][j] && numbers[j + 1][j] == numbers[j + 2][j] && numbers[j + 2][j] == numbers[j + 3][j] && numbers[j + 3][j] == numbers[j + 4][j])
//             {
//                 cout << player << " is the winner." << endl;
//                 break;
//             }
//         }
//     }
// }
int main()
{
    system("cls");
    string x, o, nameX, nameO;
    bool condition = false;
    interface();
    cout << "Enter name of Player X : ";
    cin >> nameX;
    cout << "Enter name of Player O : ";
    cin >> nameO;
    cout << "Game starts with Player X..." << endl;
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
    processing_0(nameX, false);
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
    goto playing_process;
    return 0;
}