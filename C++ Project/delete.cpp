#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    system("cls");
    int result = remove("StaffManagement.txt");
    if (result == 0)
    {
        cout << "File is deleted." << endl;
    }
    else
        cout << "Error, deleting file!" << endl;
    return 0;
}