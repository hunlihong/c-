#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <conio.h>
#include <unistd.h>
using namespace std;

int main()
{
    system("cls");
    int n;     // amount of employees
    int i = 0; // store current employees in the list
    char decision;
    fstream file;
    string date_of_hire, date_of_birth, id, name, contact, address;
    int age;
    float salary;
    file.open("employee.txt", ios::out);
    if (file)
    {
        file << left << setw(20) << "No" << left << setw(20) << "Date of Hire" << left << setw(20) << "Date of Birth" << left << setw(20) << "ID" << left << setw(20) << "Name" << left << setw(20) << "Contact" << left << setw(20) << "Address" << left << setw(20) << "Salary" << endl;
    insert:
        cout << "How may employees will be input? ANWSER = ";
        cin >> n;
        for (int j = i; j < i + n; j++)
        {
            cout << "Enter date of hire : ";
            cin >> date_of_hire;
            cout << "Enter date of birth : ";
            cin >> date_of_birth;
            cout << "Enter ID : ";
            cin >> id;
            cout << "Enter name : ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter contact : ";
            getline(cin, contact);
            cout << "Enter address : ";
            cin >> address;
            cout << "Enter salary : ";
            cin >> salary;
            // insert data into a employee.txt file
            file << left << setw(20) << (j + 1) << left << setw(20) << date_of_hire << left << setw(20) << date_of_birth << left << setw(20) << id << left << setw(20) << name << left << setw(20) << contact << left << setw(20) << address << left << setw(20) << salary << endl;
            // alert message
            cout << "*****Input successfully." << endl;
        }
        i += n;
    question:
        cout << "Would you like to insert more? [Y/N] : ";
        cin >> decision;
        decision = tolower(decision);
        if (decision == 'y')
        {
            system("cls");
            goto insert;
        }
        else if (decision == 'n')
        {
            cout << "Program is exited." << endl;
            for (int i = 3; i >= 0; i--)
            {
                cout << i << " ";
                sleep(1);
            }
            exit;
        }
        else
        {
            cout << "Error!" << endl;
            cout << "Press any key to try again : ";
            getch();
            system("cls");
            goto question;
        }
    }
    else
    {
        cout << "File is not created!" << endl;
    }
    file.close();
    return 0;
}