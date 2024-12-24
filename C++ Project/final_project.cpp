#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <algorithm>
#include <fstream>
#include <unistd.h>
using namespace std;

int staff_amount = 0;
int customer_amount = 0;
float rate = 4000;
string password, passwordSet, passwordEnter;
bool bank_account = false;
string green = "\033[32m";
string white = "\033[0m";

class Person
{
protected:
    string name, gender, dateof_birth, address, contact;

public:
    void input()
    {
        cout << "Enter name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter gender : ";
        cin >> gender;
        cout << "Enter date of birth : ";
        cin >> dateof_birth;
        cout << "Enter address : ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter contact : ";
        cin >> contact;
    }
    void output()
    {
        cout << left << setw(20) << name
             << left << setw(10) << gender << left << setw(20) << dateof_birth << left << setw(20) << address << left << setw(20) << contact;
    }
    string getName()
    {
        return name;
    }
    string getGender()
    {
        return gender;
    }
    string getDOB()
    {
        return dateof_birth;
    }
    string getAddress()
    {
        return address;
    }
    string getContact()
    {
        return contact;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setGender(string gender)
    {
        this->gender = gender;
    }
    void setDOB(string dateof_birth)
    {
        this->dateof_birth = dateof_birth;
    }
    void setAddress(string address)
    {
        this->address = address;
    }
    void setContact(string contact)
    {
        this->contact = contact;
    }
};
class Staff : public Person
{
private:
    string id, position;
    float salary;

public:
    void input()
    {
        cout << "====================================" << endl;
        cout << "Enter ID : ";
        cin >> id;
        Person::input();
        cout << "Enter position : ";
        cin.ignore();
        getline(cin, position);
        cout << "Enter salary = $";
        cin >> salary;
        transform(name.begin(), name.end(), name.begin(), towupper);
        transform(gender.begin(), gender.end(), gender.begin(), towupper);
        transform(dateof_birth.begin(), dateof_birth.end(), dateof_birth.begin(), towupper);
        transform(address.begin(), address.end(), address.begin(), towupper);
        transform(position.begin(), position.end(), position.begin(), towupper);
    }
    void output()
    {
        cout
            << left << setw(10) << id;
        Person::output();
        cout << left << setw(20) << position << left << setw(20) << salary << endl;
        for (int i = 0; i < 145; i++)
        {
            cout << "=";
        }
        cout << endl;
    }
    string getID()
    {
        return id;
    }
    string getPosition()
    {
        return position;
    }
    float getSalary()
    {
        return salary;
    }
    void setPosition(string position)
    {
        this->position = position;
    }
    void setSalary(float salary)
    {
        this->salary = salary;
    }
};
class Customer : public Person
{
private:
    string id, dateof_use;

public:
    void input()
    {
        cout << "====================================" << endl;
        cout << "Enter ID : ";
        cin >> id;
        Person::input();
        cout << "Enter date of use : ";
        cin >> dateof_use;
        transform(name.begin(), name.end(), name.begin(), towupper);
        transform(gender.begin(), gender.end(), gender.begin(), towupper);
        transform(dateof_birth.begin(), dateof_birth.end(), dateof_birth.begin(), towupper);
        transform(address.begin(), address.end(), address.begin(), towupper);
        transform(contact.begin(), contact.end(), contact.begin(), towupper);
        transform(dateof_use.begin(), dateof_use.end(), dateof_use.begin(), towupper);
    }
    void output()
    {
        cout
            << left << setw(10) << id;
        Person::output();
        cout << left << setw(20) << dateof_use << endl;
        for (int i = 0; i < 145; i++)
        {
            cout << "=";
        }
        cout << endl;
    }
    string getID()
    {
        return id;
    }
    void setID(string id)
    {
        this->id = id;
    }
    string getDOU()
    {
        return dateof_use;
    }
    void setDOU(string dateof_use)
    {
        this->dateof_use = dateof_use;
    }
};
struct Method
{
    void display(Staff staff[], string type)
    {
        if (type == "ascending")
        {
            for (int i = 0; i < staff_amount; i++)
            {
                for (int k = 0; k < staff_amount - 1; k++)
                {
                    if (staff[k].getID() > staff[k + 1].getID())
                    {
                        Staff temp = staff[k];
                        staff[k] = staff[k + 1];
                        staff[k + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < 145; i++)
            {
                cout << "=";
            }
            cout << endl;
            cout << green << left << setw(5) << "No" << left << setw(10) << "ID" << left << setw(20) << "Name"
                 << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Position" << left << setw(20) << "Salary($)" << white << endl;
            for (int i = 0; i < 145; i++)
            {
                cout << "=";
            }
            cout << endl;
            for (int i = 0; i < staff_amount; i++)
            {
                cout << left << setw(5) << (i + 1);
                staff[i].output();
            }
        }
        else if (type == "descending")
        {
            for (int i = 0; i < staff_amount; i++)
            {
                for (int k = 0; k < staff_amount - 1; k++)
                {
                    if (staff[k].getID() < staff[k + 1].getID())
                    {
                        Staff temp = staff[k];
                        staff[k] = staff[k + 1];
                        staff[k + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < 145; i++)
            {
                cout << "=";
            }
            cout << endl;
            cout << green << left << setw(5) << "No" << left << setw(10) << "ID" << left << setw(20) << "Name"
                 << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Position" << left << setw(20) << "Salary($)" << white << endl;
            for (int i = 0; i < 145; i++)
            {
                cout << "=";
            }
            cout << endl;
            for (int i = 0; i < staff_amount; i++)
            {
                cout << left << setw(5) << (i + 1);
                staff[i].output();
            }
        }
        else if (type == "high_salary")
        {
            float max_salary = staff[0].getSalary();
            for (int i = 0; i < staff_amount; i++)
            {
                if (max_salary < staff[i].getSalary())
                {
                    max_salary = staff[i].getSalary();
                }
            }
            for (int i = 0; i < staff_amount; i++)
            {
                if (max_salary == staff[i].getSalary())
                {
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    cout << green << left << setw(10) << "ID" << left << setw(20) << "Name"
                         << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Position" << left << setw(20) << "Salary($)" << white << endl;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    staff[i].output();
                }
            }
        }
        else if (type == "low_salary")
        {
            float min_salary = staff[0].getSalary();
            for (int i = 0; i < staff_amount; i++)
            {
                if (min_salary > staff[i].getSalary())
                {
                    min_salary = staff[i].getSalary();
                }
            }
            for (int i = 0; i < staff_amount; i++)
            {
                if (min_salary == staff[i].getSalary())
                {
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    cout << green << left << setw(10) << "ID" << left << setw(20) << "Name"
                         << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Position" << left << setw(20) << "Salary($)" << white << endl;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    staff[i].output();
                }
            }
        }
    }
    void display(Customer customer[], string type)
    {
        if (type == "ascending")
        {
            for (int i = 0; i < customer_amount; i++)
            {
                for (int k = 0; k < customer_amount - 1; k++)
                {
                    if (customer[k].getID() > customer[k + 1].getID())
                    {
                        Customer temp = customer[k];
                        customer[k] = customer[k + 1];
                        customer[k + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < 145; i++)
            {
                cout << "=";
            }
            cout << endl;
            cout << green << left << setw(5) << "No" << left << setw(10) << "ID" << left << setw(20) << "Name"
                 << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Date of Use" << white << endl;
            for (int i = 0; i < 145; i++)
            {
                cout << "=";
            }
            cout << endl;
            for (int i = 0; i < customer_amount; i++)
            {
                cout << left << setw(5) << (i + 1);
                customer[i].output();
            }
        }
        else if (type == "descending")
        {
            for (int i = 0; i < customer_amount; i++)
            {
                for (int k = 0; k < customer_amount - 1; k++)
                {
                    if (customer[k].getID() < customer[k + 1].getID())
                    {
                        Customer temp = customer[k];
                        customer[k] = customer[k + 1];
                        customer[k + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < 145; i++)
            {
                cout << "=";
            }
            cout << endl;
            cout << green << left << setw(5) << "No" << left << setw(10) << "ID" << left << setw(20) << "Name"
                 << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Date of Use" << white << endl;
            for (int i = 0; i < 145; i++)
            {
                cout << "=";
            }
            cout << endl;
            for (int i = 0; i < customer_amount; i++)
            {
                cout << left << setw(5) << (i + 1);
                customer[i].output();
            }
        }
    }
    void display_staff()
    {
        string data;
        fstream file;
        file.open("StaffManagement.txt", ios::in);
        if (file)
        {
            while (getline(file, data))
            {
                cout << data << endl;
            }
        }
        else
        {
            cout << "No data!" << endl;
        }
    }
    void display_customer()
    {
        string data;
        fstream file;
        file.open("CustomerManagement.txt", ios::in);
        if (file)
        {
            while (getline(file, data))
            {
                cout << data << endl;
            }
        }
        else
        {
            cout << "No data!" << endl;
        }
    }
    void search(Staff staff[], string type, bool isValid)
    {
        if (type == "id")
        {
            cout << "Enter ID to search staff : ";
            cin >> type;
            for (int i = 0; i < staff_amount; i++)
            {
                if (type == staff[i].getID())
                {
                    isValid = true;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    cout << green << left << setw(10) << "ID" << left << setw(20) << "Name"
                         << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Position" << left << setw(20) << "Salary($)" << white << endl;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    staff[i].output();
                }
            }
            if (!isValid)
            {
                cout << "Not found!" << endl;
            }
        }
        else if (type == "name")
        {
            cout << "Enter name to search staff : ";
            cin.ignore();
            getline(cin, type);
            transform(type.begin(), type.end(), type.begin(), towupper);
            for (int i = 0; i < staff_amount; i++)
            {
                if (type == staff[i].getName())
                {
                    isValid = true;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    cout << green << left << setw(10) << "ID" << left << setw(20) << "Name"
                         << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Position" << left << setw(20) << "Salary($)" << white << endl;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    staff[i].output();
                }
            }
            if (!isValid)
            {
                cout << "Not found!" << endl;
            }
        }
        else if (type == "gender")
        {
            cout << "Enter gender to search staff : ";
            cin >> type;
            transform(type.begin(), type.end(), type.begin(), towupper);
            for (int i = 0; i < staff_amount; i++)
            {
                if (type == staff[i].getGender())
                {
                    isValid = true;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    cout << green << left << setw(10) << "ID" << left << setw(20) << "Name"
                         << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Position" << left << setw(20) << "Salary($)" << white << endl;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    staff[i].output();
                }
            }
            if (!isValid)
            {
                cout << "Not found!" << endl;
            }
        }
        else if (type == "position")
        {
            cout << "Enter position to search staff : ";
            cin.ignore();
            getline(cin, type);
            transform(type.begin(), type.end(), type.begin(), towupper);
            for (int i = 0; i < staff_amount; i++)
            {
                if (type == staff[i].getPosition())
                {
                    isValid = true;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    cout << green << left << setw(10) << "ID" << left << setw(20) << "Name"
                         << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Position" << left << setw(20) << "Salary($)" << white << endl;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    staff[i].output();
                }
            }
            if (!isValid)
            {
                cout << "Not found!" << endl;
            }
        }
        else if (type == "contact")
        {
            cout << "Enter contact to search staff : ";
            cin >> type;
            for (int i = 0; i < staff_amount; i++)
            {
                if (type == staff[i].getContact())
                {
                    isValid = true;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    cout << green << left << setw(10) << "ID" << left << setw(20) << "Name"
                         << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Position" << left << setw(20) << "Salary($)" << white << endl;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    staff[i].output();
                }
            }
            if (!isValid)
            {
                cout << "Not found!" << endl;
            }
        }
    }
    void search(Customer customer[], string type, bool isValid)
    {
        if (type == "id")
        {
            cout << "Enter ID to search customer : ";
            cin >> type;
            for (int i = 0; i < customer_amount; i++)
            {
                if (type == customer[i].getID())
                {
                    isValid = true;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    cout << green << left << setw(10) << "ID" << left << setw(20) << "Name"
                         << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Date of Use" << white << endl;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    customer[i].output();
                }
            }
            if (!isValid)
            {
                cout << "Not found!" << endl;
            }
        }
        else if (type == "name")
        {
            cout << "Enter name to search customer : ";
            cin.ignore();
            getline(cin, type);
            transform(type.begin(), type.end(), type.begin(), towupper);
            for (int i = 0; i < customer_amount; i++)
            {
                if (type == customer[i].getName())
                {
                    isValid = true;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    cout << green << left << setw(10) << "ID" << left << setw(20) << "Name"
                         << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Date of Use" << white << endl;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    customer[i].output();
                }
            }
            if (!isValid)
            {
                cout << "Not found!" << endl;
            }
        }
        else if (type == "gender")
        {
            cout << "Enter gender to search customer : ";
            cin >> type;
            transform(type.begin(), type.end(), type.begin(), towupper);
            for (int i = 0; i < customer_amount; i++)
            {
                if (type == customer[i].getGender())
                {
                    isValid = true;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    cout << green << left << setw(10) << "ID" << left << setw(20) << "Name"
                         << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Date of Use" << white << endl;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    customer[i].output();
                }
            }
            if (!isValid)
            {
                cout << "Not found!" << endl;
            }
        }
        else if (type == "contact")
        {
            cout << "Enter contact to search customer : ";
            cin >> type;
            for (int i = 0; i < customer_amount; i++)
            {
                if (type == customer[i].getContact())
                {
                    isValid = true;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    cout << green << left << setw(10) << "ID" << left << setw(20) << "Name"
                         << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Date of Use" << white << endl;
                    for (int i = 0; i < 145; i++)
                    {
                        cout << "=";
                    }
                    cout << endl;
                    customer[i].output();
                }
            }
            if (!isValid)
            {
                cout << "Not found!" << endl;
            }
        }
    }
    void update(Staff staff[], string type, bool isValid)
    {
        string name, gender, dateof_birth, address, contact, position;
        float salary;
        cout << "Enter staff's ID to update data : ";
        cin >> type;
        for (int i = 0; i < staff_amount; i++)
        {
            if (type == staff[i].getID())
            {
                isValid = true;
                cout << "====================================" << endl;
                cout << "Enter new name : ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new gender : ";
                cin >> gender;
                cout << "Enter new date of birth : ";
                cin >> dateof_birth;
                cout << "Enter new address : ";
                cin.ignore();
                getline(cin, address);
                cout << "Enter new contact : ";
                cin >> contact;
                cout << "Enter new position : ";
                cin.ignore();
                getline(cin, position);
                cout << "Enter new salary : ";
                cin >> salary;
                transform(name.begin(), name.end(), name.begin(), towupper);
                transform(gender.begin(), gender.end(), gender.begin(), towupper);
                transform(dateof_birth.begin(), dateof_birth.end(), dateof_birth.begin(), towupper);
                transform(address.begin(), address.end(), address.begin(), towupper);
                transform(position.begin(), position.end(), position.begin(), towupper);
                staff[i].setName(name);
                staff[i].setGender(gender);
                staff[i].setDOB(dateof_birth);
                staff[i].setAddress(address);
                staff[i].setContact(contact);
                staff[i].setPosition(position);
                staff[i].setSalary(salary);
                cout << green << "Updated successfully." << white << endl;
            }
        }
        if (!isValid)
        {
            cout << "Not found!" << endl;
        }
    }
    void update(Customer customer[], string type, bool isValid)
    {
        string name, gender, dateof_birth, address, contact, dateof_use;
        cout << "Enter customer's ID to update data : ";
        cin >> type;
        for (int i = 0; i < customer_amount; i++)
        {
            if (type == customer[i].getID())
            {
                isValid = true;
                cout << "====================================" << endl;
                cout << "Enter new name : ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new gender : ";
                cin >> gender;
                cout << "Enter new date of birth : ";
                cin >> dateof_birth;
                cout << "Enter new address : ";
                cin.ignore();
                getline(cin, address);
                cout << "Enter new contact : ";
                cin >> contact;
                cout << "Enter new date of use : ";
                cin >> dateof_use;
                transform(name.begin(), name.end(), name.begin(), towupper);
                transform(gender.begin(), gender.end(), gender.begin(), towupper);
                transform(dateof_birth.begin(), dateof_birth.end(), dateof_birth.begin(), towupper);
                transform(address.begin(), address.end(), address.begin(), towupper);
                transform(dateof_use.begin(), dateof_use.end(), dateof_use.begin(), towupper);
                customer[i].setName(name);
                customer[i].setGender(gender);
                customer[i].setDOB(dateof_birth);
                customer[i].setAddress(address);
                customer[i].setContact(contact);
                customer[i].setDOU(dateof_use);
                cout << green << "Updated successfully." << white << endl;
            }
        }
        if (!isValid)
        {
            cout << "Not found!" << endl;
        }
    }
    void delete_staff(Staff staff[], string type, bool isValid)
    {
        if (type == "delete")
        {
            cout << "Enter ID to delete staff's data : ";
            cin >> type;
            for (int i = 0; i < staff_amount; i++)
            {
                if (type == staff[i].getID())
                {
                    isValid = true;
                    for (int k = i; k < staff_amount - 1; k++)
                    {
                        staff[k] = staff[k + 1];
                    }
                    staff_amount--;
                    cout << green << "Deleted successfully." << white << endl;
                }
            }
            if (!isValid)
            {
                cout << "Not found!" << endl;
            }
        }
    }
    void delete_customer(Customer customer[], string type, bool isValid)
    {
        if (type == "delete")
        {
            cout << "Enter ID to delete customer's data : ";
            cin >> type;
            for (int i = 0; i < customer_amount; i++)
            {
                if (type == customer[i].getID())
                {
                    isValid = true;
                    for (int k = i; k < customer_amount - 1; k++)
                    {
                        customer[k] = customer[k + 1];
                    }
                }
                customer_amount--;
                cout << green << "Deleted successfully." << white << endl;
            }
            if (!isValid)
            {
                cout << "Not found!" << endl;
            }
        }
    }
    void save(Staff staff[])
    {
        char decision;
        cout << "Click any key to create a file : ";
        getch();
        cout << endl;
        cout << "File is created that is name as: 'StaffManagement.txt'" << endl;
        cout << "??? Are you sure to save all the staff's data that has been input? [Y/N] : ";
        cin >> decision;
        if (decision == 'Y' || decision == 'y')
        {
            fstream file;
            file.open("StaffManagement.txt", ios::app);
            for (int i = 0; i < 145; i++)
            {
                file << "=";
            }
            file << endl;
            file << left << setw(5) << "No" << left << setw(10) << "ID" << left << setw(20) << "Name"
                 << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Position" << left << setw(20) << "Salary($)" << endl;
            for (int i = 0; i < 145; i++)
            {
                file << "=";
            }
            file << endl;
            for (int i = 0; i < staff_amount; i++)
            {
                file << left << setw(5) << (i + 1);
                file << left << setw(10) << staff[i].getID() << left << setw(20) << staff[i].getName()
                     << left << setw(10) << staff[i].getGender() << left << setw(20) << staff[i].getDOB() << left << setw(20) << staff[i].getAddress() << left << setw(20) << staff[i].getContact() << left << setw(20) << staff[i].getPosition() << left << setw(20) << staff[i].getSalary() << endl;
                for (int i = 0; i < 145; i++)
                {
                    file << "=";
                }
                file << endl;
            }
            cout << green << "Saved successfully." << white << endl;
        }
        else if (decision == 'N' || decision == 'n')
        {
        }
        else
        {
            cout << "Error!" << endl;
        }
    }
    void save(Customer customer[])
    {
        char decision;
        cout << "Click any key to create a file : ";
        getch();
        cout << endl;
        cout << "File is created that is name as: 'CustomerManagement.txt'" << endl;
        cout << "??? Are you sure to save all the staff's data that has been input? [Y/N] : ";
        cin >> decision;
        if (decision == 'Y' || decision == 'y')
        {
            fstream file;
            file.open("CustomerManagement.txt", ios::app);
            for (int i = 0; i < 145; i++)
            {
                file << "=";
            }
            file << endl;
            file << left << setw(5) << "No" << left << setw(10) << "ID" << left << setw(20) << "Name"
                 << left << setw(10) << "Gender" << left << setw(20) << "Date of Birth" << left << setw(20) << "Address" << left << setw(20) << "Contact" << left << setw(20) << "Date of Use" << endl;
            for (int i = 0; i < 145; i++)
            {
                file << "=";
            }
            file << endl;
            for (int i = 0; i < customer_amount; i++)
            {
                file << left << setw(5) << (i + 1) << left << setw(10) << customer[i].getID() << left << setw(20) << customer[i].getName()
                     << left << setw(10) << customer[i].getGender() << left << setw(20) << customer[i].getDOB() << left << setw(20) << customer[i].getAddress() << left << setw(20) << customer[i].getContact() << left << setw(20) << customer[i].getDOU() << endl;
                for (int i = 0; i < 145; i++)
                {
                    file << "=";
                }
                file << endl;
            }
            cout << green << "Saved successfully." << white << endl;
        }
        else if (decision == 'N' || decision == 'n')
        {
        }
        else
        {
            cout << "Error!" << endl;
        }
    }
};
struct Mobile
{
    float usd = 0, riel, cash_in = 0, cash_out;
    char cash;
    string name, gender, dob, address, contact;
    void createAcc()
    {
        cout << "You have to create an account to use." << endl;
        cout << "Enter your full name = ";
        cin.ignore();
        getline(cin, name);
        transform(name.begin(), name.end(), name.begin(), towupper);
        cout << "Enter your gender = ";
        cin >> gender;
        transform(gender.begin(), gender.end(), gender.begin(), towupper);
        cout << "Enter date of birth = ";
        cin >> dob;
        transform(dob.begin(), dob.end(), dob.begin(), towupper);
        cout << "Enter your address = ";
        cin.ignore();
        getline(cin, address);
        transform(address.begin(), address.end(), address.begin(), towupper);
        cout << "Enter your phone number = ";
        cin >> contact;
        cout << "Create a password = ";
        cin.ignore();
        getline(cin, passwordSet);
        cout << "Please wait for a moment, we are creating mobile account for you." << endl;
        cout << "Loading";
        for (int i = 0; i < 5; i++)
        {
            sleep(1);
            cout << " .";
        }
        cout << endl;
        cout << "You account is created." << endl;
        cout << "Press any key to login : ";
        getch();
        system("cls");
        bank_account = true;
    }
    void account()
    {
        system("cls");
        cout << green << ">>>>>>>>>> Account <<<<<<<<<<" << white << endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "=";
        }
        cout << endl;
        cout << "| USD Account = $" << left << setw(20) << usd << "  |" << endl;
        cout << "|";
        for (int i = 0; i < 38; i++)
        {
            cout << "=";
        }
        cout << "|" << endl;
        cout << "| KH  Account = R" << left << setw(20) << riel << "  |" << endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "=";
        }
        cout << endl;
    }
    void deposit(string type)
    {
        if (type == "usd")
        {
            cout << "Choose type of cash [$/R] = ";
            cin >> cash;
            if (cash == '$')
            {
                cout << "Deposit = $";
                cin >> cash_in;
                cout << "Enter password to confirm : ";
                cin >> passwordEnter;
                if (passwordEnter == passwordSet)
                {
                    usd += cash_in;
                    cout << cash_in << "$ is deposited into USD account." << endl;
                }
                else
                {
                    cout << "Wrong password!" << endl;
                }
                cout << "Press any key to see account : ";
                getch();
                account();
            }
            else if (cash == 'R')
            {
                cout << "Deposit = R";
                cin >> cash_in;
                cout << "Enter password to confirm : ";
                cin >> passwordEnter;
                if (passwordEnter == passwordSet)
                {
                    usd += cash_in / rate;
                    cout << cash_in << "R is deposited into USD account." << endl;
                }
                else
                {
                    cout << "Wrong password!" << endl;
                }
                cout << cash_in << "R is deposited into USD account." << endl;
                cout << "Press any key to see account : ";
                getch();
                account();
            }
            else
            {
                cout << "Error!" << endl;
            }
        }
        else if (type == "riel")
        {
            cout << "Choose type of cash [$/R] = ";
            cin >> cash;
            if (cash == '$')
            {
                cout << "Deposit = $";
                cin >> cash_in;
                cout << "Enter password to confirm : ";
                cin >> passwordEnter;
                if (passwordEnter == passwordSet)
                {
                    riel += cash_in * rate;
                    cout << cash_in << "$ is deposited into KH account." << endl;
                }
                else
                {
                    cout << "Wrong password!" << endl;
                }
                cout << "Press any key to see account : ";
                getch();
                account();
            }
            else if (cash == 'R')
            {
                cout << "Deposit = R";
                cin >> cash_in;
                cout << "Enter password to confirm : ";
                cin >> passwordEnter;
                if (passwordEnter == passwordSet)
                {
                    riel += cash_in;
                    cout << cash_in << "R is deposited into KH account." << endl;
                }
                else
                {
                    cout << "Wrong password!" << endl;
                }
                cout << "Press any key to see account : ";
                getch();
                account();
            }
            else
            {
                cout << "Error!" << endl;
            }
        }
    }
    void withdraw(string type)
    {
        if (type == "usd")
        {
            cout << "Choose type of cash [$/R] = ";
            cin >> cash;
            if (cash == '$')
            {
                cout << "Withdraw = $";
                cin >> cash_out;
                if (cash_out > usd)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        usd -= cash_out;
                        cout << cash_out << "$ is withdrawed from USD account." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
            else if (cash == 'R')
            {
                cout << "Withdraw = R";
                cin >> cash_out;
                if (cash_out / rate > usd)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        usd -= cash_out / rate;
                        cout << cash_out << "R is withdrawed from USD account." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
        }
        else if (type == "riel")
        {
            cout << "Choose type of cash [$/R] = ";
            cin >> cash;
            if (cash == '$')
            {
                cout << "Withdraw = $";
                cin >> cash_out;
                if (cash_out * rate > riel)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        riel -= cash_out * rate;
                        cout << cash_out << "$ is withdrawed from USD account." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
            else if (cash == 'R')
            {
                cout << "Withdraw = R";
                cin >> cash_out;
                if (cash_out > riel)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        riel -= cash_out;
                        cout << cash_out << "R is withdrawed from USD account." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
        }
    }
    void transfer(string type)
    {
        if (type == "usd->riel")
        {
            cout << "Choose type of cash [$/R] = ";
            cin >> cash;
            if (cash == '$')
            {
                cout << "Transfer = $";
                cin >> cash_out;
                if (cash_out > usd)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        usd -= cash_out;
                        riel += cash_out * rate;
                        cout << cash_out << "$ is transfered to KH account." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
            else if (cash == 'R')
            {
                cout << "Transfer = R";
                cin >> cash_out;
                if (cash_out / rate > usd)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        usd -= cash_out / rate;
                        riel += cash_out;
                        cout << cash_out << "R is transfered to KH account." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
        }
        else if (type == "riel->usd")
        {
            cout << "Choose type of cash [$/R] = ";
            cin >> cash;
            if (cash == '$')
            {
                cout << "Transfer = $";
                cin >> cash_out;
                if (cash_out * rate > riel)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        riel -= cash_out * rate;
                        usd += cash_out;
                        cout << cash_out << "$ is transfered to USD account." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
            else if (cash == 'R')
            {
                cout << "Transfer = R";
                cin >> cash_out;
                if (cash_out > riel)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        riel -= cash_out;
                        usd += cash_out / rate;
                        cout << cash_out << "R is transfered to USD account." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
        }
    }
    void transfer(string type, string receive)
    {
        if (receive != "ATM")
        {
            cout << "Enter received account (Bar Kong) : ";
            cin >> receive;
        }
        if (type == "usd")
        {
            cout << "Choose type of cash [$/R] = ";
            cin >> cash;
            if (cash == '$')
            {
                cout << "Transfer = $";
                cin >> cash_out;
                if (cash_out > usd)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        usd -= cash_out;
                        cout << cash_out << "$ is transfered from USD account to " << receive << "." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
            else if (cash == 'R')
            {
                cout << "Transfer = R";
                cin >> cash_out;
                if (cash_out / rate > usd)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        usd -= cash_out / rate;
                        cout << cash_out << "R is transfered from USD account to " << receive << "." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
        }
        else if (type == "riel")
        {
            cout << "Choose type of cash [$/R] = ";
            cin >> cash;
            if (cash == '$')
            {
                cout << "Transfer = $";
                cin >> cash_out;
                if (cash_out * rate > riel)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        riel -= cash_out * rate;
                        cout << cash_out << "$ is transfered from KH account to " << receive << "." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
            else if (cash == 'R')
            {
                cout << "Transfer = R";
                cin >> cash_out;
                if (cash_out > riel)
                {
                    cout << "Insufficient balance!" << endl;
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
                else
                {
                    cout << "Enter password to confirm : ";
                    cin >> passwordEnter;
                    if (passwordEnter == passwordSet)
                    {
                        riel -= cash_out;
                        cout << cash_out << "$ is transfered from KH account to " << receive << "." << endl;
                    }
                    else
                    {
                        cout << "Wrong password!" << endl;
                    }
                    cout << "Press any key to see account : ";
                    getch();
                    account();
                }
            }
        }
    }
    void setting()
    {
        char change_data;
        string new_address, new_contact, new_password, confirm_password;
        cout << green << ">>>>>>>> Profile" << white << endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "=";
        }
        cout << endl;
        cout << left << setw(20) << " Full name " << left << setw(20) << name << endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "=";
        }
        cout << endl;
        cout << left << setw(20) << " Gender " << left << setw(20) << gender << endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "=";
        }
        cout << endl;
        cout << left << setw(20) << " Date of birth " << left << setw(20) << dob << endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "=";
        }
        cout << endl;
        cout << left << setw(20) << " Address " << left << setw(20) << address << endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "=";
        }
        cout << endl;
        cout << left << setw(20) << " Phone number " << left << setw(20) << contact << endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "=";
        }
        cout << endl;
        cout << left << setw(20) << " Password ";
        for (int i = 0; i < passwordSet.length(); i++)
        {
            cout << "*";
        }
        cout << endl;
        for (int i = 0; i < 40; i++)
        {
            cout << "=";
        }
        cout << endl;
        cout << "Note: Changeable data can be only address, contact and password." << endl;
        cout << "Do you want to change your data? [Y/N] = ";
        cin >> change_data;
        if (change_data == 'Y' || change_data == 'y')
        {
            cout << "Remember: If you have any modifying troubles, please contact us or come to our venue. Thank you!" << endl;
            cout << "Change address ? [Y/N] = ";
            cin >> change_data;
            if (change_data == 'Y' || change_data == 'y')
            {
                cout << "Enter your new address = ";
                cin.ignore();
                getline(cin, new_address);
                cout << "Enter password to confirm : ";
                cin >> passwordEnter;
                if (passwordEnter == passwordSet)
                {
                    address = new_address;
                    transform(address.begin(), address.end(), address.begin(), towupper);
                    cout << "Your address has been changed." << endl;
                }
                else
                {
                    cout << "Wrong password!" << endl;
                }
            }
            cout << "Change phone number ? [Y/N] = ";
            cin >> change_data;
            if (change_data == 'Y' || change_data == 'y')
            {
                cout << "Enter your new phone number  = ";
                cin >> new_contact;
                cout << "Enter password to confirm : ";
                cin >> passwordEnter;
                if (passwordEnter == passwordSet)
                {
                    new_contact = new_contact;
                    cout << "Your phone number has been changed." << endl;
                }
                else
                {
                    cout << "Wrong password!" << endl;
                }
            }
            cout << "Change password ? [Y/N] = ";
            cin >> change_data;
            if (change_data == 'Y' || change_data == 'y')
            {
                cout << "Enter your current password  = ";
                cin >> passwordEnter;
                cout << "Enter your new password = ";
                cin >> new_password;
                cout << "Retype your new password = ";
                cin >> confirm_password;
                if (passwordEnter == passwordSet && new_password == confirm_password)
                {
                    passwordSet == confirm_password;
                    cout << "Your password has been changed." << endl;
                }
                else
                {
                    cout << "Wrong password!" << endl;
                }
            }
        }
    }
};
int main()
{
    system("cls");
    Staff staff[100];
    Customer customer[100];
    Method method;
    Mobile bank;
    int option;
    int current_staff, current_customer;
    string receive;
    float total = 0;
    cout << fixed << showpoint << setprecision(2);
Home:
    do
    {
        system("cls");
        cout << "===============> Management System <===============" << endl;
        cout << "___________________________________________________" << endl;
        cout << "|                       |                         |" << endl;
        cout << "|  1. Staff Management  | 2. Customer Management  |" << endl;
        cout << "|_______________________|_________________________|" << endl;
        cout << "|                  |                 |            |" << endl;
        cout << "|  3. BIU Mobile   |    4. About     |  5. Exit   |" << endl;
        cout << "|__________________|_________________|____________|" << endl;
        cout << endl;
        cout << "[Option] = ";
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            cout << "Enter password = ";
            cin.ignore();
            getline(cin, password);
            if (password != "C++ Programming")
            {
                cout << "Wrong password!" << endl;
                cout << "Press any key to try again : ";
                getch();
                goto Home;
            }
            do
            {
                system("cls");
                cout << "================ STAFF MANAGEMENT ================" << endl;
                cout << "_________________________________________________" << endl;
                cout << "|                       |                       |" << endl;
                cout << "|       1. Insert       |      2. Display       |" << endl;
                cout << "|_______________________|_______________________|" << endl;
                cout << "|                       |                       |" << endl;
                cout << "|       3. Search       |      4. Update        |" << endl;
                cout << "|_______________________|_______________________|" << endl;
                cout << "|                       |                       |" << endl;
                cout << "|       5. Save         |      6. Delete        |" << endl;
                cout << "|_______________________|_______________________|" << endl;
                cout << "|                                               |" << endl;
                cout << "|                   7. Back                     |" << endl;
                cout << "|_______________________________________________|" << endl;
                cout << endl;
                cout << "[Option] = ";
                cin >> option;
                switch (option)
                {
                case 1:
                    system("cls");
                    cout << "How staff do you want to insert? ANSWER = ";
                    cin >> current_staff;
                    if (current_staff > 0)
                    {
                        for (int i = staff_amount; i < staff_amount + current_staff; i++)
                        {
                            staff[i].input();
                            cout << green << "Inserted successfully." << white << endl;
                        }
                        staff_amount += current_staff;
                    }
                    else
                    {
                        cout << "Error! Amount has to be greater or equal to one at least." << endl;
                    }
                    break;
                case 2:
                    if (staff_amount > 0)
                    {
                        do
                        {
                            system("cls");
                            cout << "1. Display from a text file" << endl;
                            cout << "2. Display from RAM of a device" << endl;
                            cout << "3. Back" << endl;
                            cout << "[Option] = ";
                            cin >> option;
                            switch (option)
                            {
                            case 1:
                                method.display_staff();
                                break;
                            case 2:
                                do
                                {
                                    system("cls");
                                    cout << "1. Ascending order" << endl;
                                    cout << "2. Descending order" << endl;
                                    cout << "3. Salary" << endl;
                                    cout << "4. Back" << endl;
                                    cout << "[Option] = ";
                                    cin >> option;
                                    switch (option)
                                    {
                                    case 1:
                                        method.display(staff, "ascending");
                                        break;
                                    case 2:
                                        method.display(staff, "descending");
                                        break;
                                    case 3:
                                        do
                                        {
                                            system("cls");
                                            cout << "1. The highest paid" << endl;
                                            cout << "2. The lowest paid" << endl;
                                            cout << "3. Back" << endl;
                                            cout << "[Option] = ";
                                            cin >> option;
                                            switch (option)
                                            {
                                            case 1:
                                                method.display(staff, "high_salary");
                                                break;
                                            case 2:
                                                method.display(staff, "low_salary");
                                                break;
                                            case 3:
                                                break;
                                            default:
                                                cout << "Error!" << endl;
                                                break;
                                            }
                                            if (option != 3)
                                            {
                                                cout << "Press any key to continue : ";
                                                getch();
                                            }
                                        } while (option != 3);
                                        break;
                                    case 4:
                                        break;
                                    default:
                                        cout << "Error!" << endl;
                                        break;
                                    }
                                    if (option != 4)
                                    {
                                        cout << "Press any key to continue : ";
                                        getch();
                                    }
                                } while (option != 4);
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Error!" << endl;
                                break;
                            }
                            if (option != 3)
                            {
                                cout << "Press any key to continue : ";
                                getch();
                            }
                        } while (option != 3);
                    }
                    else
                    {
                        cout << "No staff!" << endl;
                    }
                    break;
                case 3:
                    if (staff_amount > 0)
                    {
                        do
                        {
                            system("cls");
                            cout << "1. Search by ID" << endl;
                            cout << "2. Search by name" << endl;
                            cout << "3. Search by gender" << endl;
                            cout << "4. Search by position" << endl;
                            cout << "5. Search by contact" << endl;
                            cout << "6. Back" << endl;
                            cout << "[Option] = ";
                            cin >> option;
                            switch (option)
                            {
                            case 1:
                                method.search(staff, "id", false);
                                break;
                            case 2:
                                method.search(staff, "name", false);
                                break;
                            case 3:
                                method.search(staff, "gender", false);
                                break;
                            case 4:
                                method.search(staff, "position", false);
                                break;
                            case 5:
                                method.search(staff, "contact", false);
                                break;
                            case 6:
                                break;
                            default:
                                cout << "Error!" << endl;
                                break;
                            }
                            if (option != 6)
                            {
                                cout << "Press any key to continue : ";
                                getch();
                            }
                        } while (option != 6);
                    }
                    else
                    {
                        cout << "No staff!" << endl;
                    }
                    break;
                case 4:
                    if (staff_amount > 0)

                        method.update(staff, "update", false);
                    else
                        cout << "No staff!" << endl;
                    break;
                case 5:
                    if (staff_amount > 0)
                        method.save(staff);
                    else
                        cout << "No staff!" << endl;
                    break;
                case 6:
                    if (staff_amount > 0)
                        method.delete_staff(staff, "delete", false);
                    else
                        cout << "No staff!" << endl;
                    break;
                case 7:
                    break;
                default:
                    cout << "Error!" << endl;
                    break;
                }
                if (option != 7)
                {
                    cout << "Press any key to continue : ";
                    getch();
                }
            } while (option != 7);
            break;
        case 2:
            system("cls");
            cout << "Enter password = ";
            cin.ignore();
            getline(cin, password);
            if (password != "C++ Programming")
            {
                cout << "Wrong password!" << endl;
                cout << "Press any key to try again : ";
                getch();
                goto Home;
            }
            do
            {
                system("cls");
                cout << "============== CUSTOMER MANAGEMENT ==============" << endl;
                cout << "_________________________________________________" << endl;
                cout << "|                       |                       |" << endl;
                cout << "|       1. Insert       |      2. Display       |" << endl;
                cout << "|_______________________|_______________________|" << endl;
                cout << "|                       |                       |" << endl;
                cout << "|       3. Search       |      4. Update        |" << endl;
                cout << "|_______________________|_______________________|" << endl;
                cout << "|                       |                       |" << endl;
                cout << "|       5. Save         |      6. Delete        |" << endl;
                cout << "|_______________________|_______________________|" << endl;
                cout << "|                                               |" << endl;
                cout << "|                   7. Back                     |" << endl;
                cout << "|_______________________________________________|" << endl;
                cout << endl;
                cout << "[Option] = ";
                cin >> option;
                switch (option)
                {
                case 1:
                    system("cls");
                    cout << "How many customers do you want to insert? ANSWER = ";
                    cin >> current_customer;
                    if (current_customer > 0)
                    {
                        for (int i = customer_amount; i < customer_amount + current_customer; i++)
                        {
                            customer[i].input();
                            cout << green << "Inserted successfully." << white << endl;
                        }
                        customer_amount += current_customer;
                    }
                    else
                    {
                        cout << "Error! Amount have to be greater or equal to zero." << endl;
                    }
                    break;
                case 2:
                    if (customer_amount > 0)
                    {
                        do
                        {
                            system("cls");
                            cout << "1. Display from a text file" << endl;
                            cout << "2. Display from RAM of a device" << endl;
                            cout << "3. Back" << endl;
                            cout << "[Option] = ";
                            cin >> option;
                            switch (option)
                            {
                            case 1:
                                method.display_customer();
                                break;
                            case 2:
                                do
                                {
                                    system("cls");
                                    cout << "1. Ascending order" << endl;
                                    cout << "2. Descending order" << endl;
                                    cout << "3. Back" << endl;
                                    cout << "[Option] = ";
                                    cin >> option;
                                    switch (option)
                                    {
                                    case 1:
                                        method.display(customer, "ascending");
                                        break;
                                    case 2:
                                        method.display(customer, "descending");
                                        break;
                                    case 3:
                                        break;
                                    default:
                                        cout << "Error!" << endl;
                                        break;
                                    }
                                    if (option != 3)
                                    {
                                        cout << "Press any key to continue : ";
                                        getch();
                                    }
                                } while (option != 3);
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Error!" << endl;
                                break;
                            }
                            if (option != 3)
                            {
                                cout << "Press any key to continue : ";
                                getch();
                            }
                        } while (option != 3);
                    }
                    else
                        cout << "No customer!" << endl;
                    break;
                case 3:
                    if (customer_amount > 0)
                    {
                        do
                        {
                            system("cls");
                            cout << "1. Search by ID" << endl;
                            cout << "2. Search by name" << endl;
                            cout << "3. Search by gender" << endl;
                            cout << "4. Search by contact" << endl;
                            cout << "5. Back" << endl;
                            cout << "[Option] = ";
                            cin >> option;
                            switch (option)
                            {
                            case 1:
                                method.search(customer, "id", false);
                                break;
                            case 2:
                                method.search(customer, "name", false);
                                break;
                            case 3:
                                method.search(customer, "gender", false);
                                break;
                            case 4:
                                method.search(customer, "contact", false);
                                break;
                            case 5:
                                break;
                            default:
                                cout << "Error!" << endl;
                                break;
                            }
                            if (option != 5)
                            {
                                cout << "Press any key to continue : ";
                                getch();
                            }
                        } while (option != 5);
                    }
                    else
                        cout << "No customer!" << endl;
                    break;
                case 4:
                    if (customer_amount > 0)
                        method.update(customer, "update", false);
                    else
                        cout << "No customer!" << endl;
                    break;
                case 5:
                    if (customer_amount > 0)
                        method.save(customer);
                    else
                        cout << "No customer!" << endl;
                    break;
                case 6:
                    if (customer_amount > 0)
                        method.delete_customer(customer, "delete", false);
                    else
                        cout << "No customer!" << endl;
                    break;
                case 7:
                    break;
                default:
                    cout << "Error!" << endl;
                    break;
                }
                if (option != 7)
                {
                    cout << "Press any key to continue : ";
                    getch();
                }
            } while (option != 7);
            break;
        case 3:
            system("cls");
            if (bank_account == false)
            {
                bank.createAcc();
            }
            cout << "Enter password to login into BIU Mobile = ";
            cin >> passwordEnter;
            if (passwordEnter != passwordSet)
            {
                cout << "Wrong password!" << endl;
                cout << "Press any key to try again : ";
                getch();
                goto Home;
            }
            do
            {
                system("cls");
                cout << "___________________________________________________" << endl;
                cout << "|                                                 |" << endl;
                cout << "|                   BIU Mobile                    |" << endl;
                cout << "|_________________________________________________|" << endl;
                cout << "|               |                |                |" << endl;
                cout << "|  1. Account   |   2. Deposit   |  3. Withdraw   |" << endl;
                cout << "|_______________|________________|________________|" << endl;
                cout << "|               |                |                |" << endl;
                cout << "|  4. Payment   |   5. Transfer  |  6. Setting    |" << endl;
                cout << "|_______________|________________|________________|" << endl;
                cout << "|                                                 |" << endl;
                cout << "|                    7. Back                      |" << endl;
                cout << "|_________________________________________________|" << endl;
                cout << endl;
                cout << "[Option] = ";
                cin >> option;
                switch (option)
                {
                case 1:
                    bank.account();
                    break;
                case 2:
                    do
                    {
                        system("cls");
                        cout << "___________________________________________________" << endl;
                        cout << "|                                                 |" << endl;
                        cout << "|                     Deposit                     |" << endl;
                        cout << "|_________________________________________________|" << endl;
                        cout << "|                        |                        |" << endl;
                        cout << "|   1. To USD Account    |    2. To KH Account    |" << endl;
                        cout << "|________________________|________________________|" << endl;
                        cout << "|                                                 |" << endl;
                        cout << "|                     3. Back                     |" << endl;
                        cout << "|_________________________________________________|" << endl;
                        cout << endl;
                        cout << "[Option] = ";
                        cin >> option;
                        switch (option)
                        {
                        case 1:
                            bank.deposit("usd");
                            break;
                        case 2:
                            bank.deposit("riel");
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Error!" << endl;
                            break;
                        }
                        if (option != 3)
                        {
                            cout << "Press any key to continue : ";
                            getch();
                        }
                    } while (option != 3);
                    break;
                case 3:
                    do
                    {
                        system("cls");
                        cout << "___________________________________________________" << endl;
                        cout << "|                                                 |" << endl;
                        cout << "|                     Withdraw                    |" << endl;
                        cout << "|_________________________________________________|" << endl;
                        cout << "|                        |                        |" << endl;
                        cout << "|  1. From USD Account   |   2. From KH Account   |" << endl;
                        cout << "|________________________|________________________|" << endl;
                        cout << "|                                                 |" << endl;
                        cout << "|                     3. Back                     |" << endl;
                        cout << "|_________________________________________________|" << endl;
                        cout << endl;
                        cout << "[Option] = ";
                        cin >> option;
                        switch (option)
                        {
                        case 1:
                            bank.withdraw("usd");
                            break;
                        case 2:
                            bank.withdraw("riel");
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Error!" << endl;
                            break;
                        }
                        if (option != 3)
                        {
                            cout << "Press any key to continue : ";
                            getch();
                        }
                    } while (option != 3);
                    break;
                case 4:
                    float cash_in, cash_out;
                    do
                    {
                        system("cls");
                        cout << "________________________________________________________________" << endl;
                        cout << "|                                                              |" << endl;
                        cout << "|                            Payment                           |" << endl;
                        cout << "|______________________________________________________________|" << endl;
                        cout << "|                        |                                     |" << endl;
                        cout << "|   1. Top up            |    2. Water, Electricity, trash     |" << endl;
                        cout << "|________________________|_____________________________________|" << endl;
                        cout << "|                        |                                     |" << endl;
                        cout << "|   3. Public Service    |    4. Internet and television       |" << endl;
                        cout << "|________________________|_____________________________________|" << endl;
                        cout << "|                        |                                     |" << endl;
                        cout << "|   5. Insurance         |    6. Education                     |" << endl;
                        cout << "|________________________|_____________________________________|" << endl;
                        cout << "|                        |                                     |" << endl;
                        cout << "|   7. Charity           |    8. Back                          |" << endl;
                        cout << "|________________________|_____________________________________|" << endl;
                        cout << endl;
                        cout << "[Option] = ";
                        cin >> option;
                        switch (option)
                        {
                        case 1:
                            do
                            {
                                system("cls");
                                string number;
                                cout << "Choose account" << endl;
                                cout << "1. USD account" << endl;
                                cout << "2. KH account" << endl;
                                cout << "3. Back" << endl;
                                cout << "[Option] = ";
                                cin >> option;
                                switch (option)
                                {
                                case 1:
                                    system("cls");
                                    cout << "Enter phone number = ";
                                    cin >> number;
                                    cout << "Top up = $";
                                    cin >> cash_out;
                                    if (cash_out > bank.usd)
                                    {
                                        cout << "Insufficient balance!" << endl;
                                    }
                                    else
                                    {
                                        cout << "Enter password to confirm : ";
                                        cin >> passwordEnter;
                                        if (passwordEnter == passwordSet)
                                        {
                                            bank.usd -= cash_out;
                                            cout << "You topped up $" << cash_out << " from USD account for " << number << "." << endl;
                                        }
                                        else
                                        {
                                            cout << "Wrong password!" << endl;
                                        }
                                        cout << "Press any key to see account : ";
                                        getch();
                                        bank.account();
                                    }
                                    break;
                                case 2:
                                    system("cls");
                                    cout << "Enter phone number = ";
                                    cin >> number;
                                    cout << "Top up = $";
                                    cin >> cash_out;
                                    if (cash_out * rate > bank.riel)
                                    {
                                        cout << "Insufficient balance!" << endl;
                                    }
                                    else
                                    {
                                        cout << "Enter password to confirm : ";
                                        cin >> passwordEnter;
                                        if (passwordEnter == passwordSet)
                                        {
                                            bank.riel -= cash_out * rate;
                                            cout << "You topped up $" << cash_out << " from KH account for " << number << "." << endl;
                                        }
                                        else
                                        {
                                            cout << "Wrong password!" << endl;
                                        }
                                        cout << "Press any key to see account : ";
                                        getch();
                                        bank.account();
                                    }
                                    break;
                                case 3:
                                    break;
                                default:
                                    cout << "Error!" << endl;
                                    break;
                                }
                                if (option != 3)
                                {
                                    cout << "Press any key to continue : ";
                                    getch();
                                }
                            } while (option != 3);
                            break;
                        case 2:
                            system("cls");
                            float cash[3];
                            cout << "_Electricity = R";
                            cin >> cash[0];
                            cout << "_Water = R";
                            cin >> cash[1];
                            cout << "_Trash = R";
                            cin >> cash[2];
                            for (float i : cash)
                            {
                                total += i;
                            }
                            cout << "---------------------" << endl;
                            cout << "Total = R" << total << endl;
                            cout << "Choose account" << endl;
                            cout << "1. USD account" << endl;
                            cout << "2. KH account" << endl;
                            cout << "3. Back" << endl;
                            cout << "[Option] = ";
                            cin >> option;
                            switch (option)
                            {
                            case 1:
                                if (total / rate > bank.usd)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.usd -= total / rate;
                                        cout << "You paid R" << total << " from USD account." << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 2:
                                if (total > bank.riel)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.riel -= total;
                                        cout << "You paid R" << total << " from KH account.;" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Error!" << endl;
                                break;
                            }
                            break;
                        case 3:
                            system("cls");
                            cout << "_Public service = R";
                            cin >> cash_out;
                            cout << "Choose account" << endl;
                            cout << "1. USD account" << endl;
                            cout << "2. KH account" << endl;
                            cout << "3. Back" << endl;
                            cout << "[Option] = ";
                            cin >> option;
                            switch (option)
                            {
                            case 1:
                                if (cash_out / rate > bank.usd)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.usd -= cash_out / rate;
                                        cout << "You paid R" << cash_out << " from USD account." << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 2:
                                if (cash_out > bank.riel)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.riel -= cash_out;
                                        cout << "You paid R" << cash_out << " from KH account.;" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Error!" << endl;
                                break;
                            }
                            break;
                        case 4:
                            system("cls");
                            cout << "_Internet = R";
                            cin >> cash[0];
                            cout << "_Television = R";
                            cin >> cash[1];
                            cash[2] = 0;
                            for (float i : cash)
                            {
                                total += i;
                            }
                            cout << "---------------------" << endl;
                            cout << "Total = R" << total << endl;
                            cout << "Choose account" << endl;
                            cout << "1. USD account" << endl;
                            cout << "2. KH account" << endl;
                            cout << "3. Back" << endl;
                            cout << "[Option] = ";
                            cin >> option;
                            switch (option)
                            {
                            case 1:
                                if (total / rate > bank.usd)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.usd -= total / rate;
                                        cout << "You paid R" << total << " from USD account." << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 2:
                                if (total > bank.riel)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.riel -= total;
                                        cout << "You paid R" << total << " from KH account.;" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Error!" << endl;
                                break;
                            }
                            break;
                        case 5:
                            system("cls");
                            cout << "_Insurance = R";
                            cin >> cash_out;
                            cout << "Choose account" << endl;
                            cout << "1. USD account" << endl;
                            cout << "2. KH account" << endl;
                            cout << "3. Back" << endl;
                            cout << "[Option] = ";
                            cin >> option;
                            switch (option)
                            {
                            case 1:
                                if (cash_out / rate > bank.usd)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.usd -= cash_out / rate;
                                        cout << "You paid R" << cash_out << " from USD account." << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 2:
                                if (cash_out > bank.riel)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.riel -= cash_out;
                                        cout << "You paid R" << cash_out << " from KH account.;" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Error!" << endl;
                                break;
                            }
                            break;
                        case 6:
                            system("cls");
                            cout << "_Education = R";
                            cin >> cash_out;
                            cout << "Choose account" << endl;
                            cout << "1. USD account" << endl;
                            cout << "2. KH account" << endl;
                            cout << "3. Back" << endl;
                            cout << "[Option] = ";
                            cin >> option;
                            switch (option)
                            {
                            case 1:
                                if (cash_out / rate > bank.usd)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.usd -= cash_out / rate;
                                        cout << "You paid R" << cash_out << " from USD account." << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 2:
                                if (cash_out > bank.riel)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.riel -= cash_out;
                                        cout << "You paid R" << cash_out << " from KH account.;" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Error!" << endl;
                                break;
                            }
                            break;
                        case 7:
                            system("cls");
                            cout << "_Charity = R";
                            cin >> cash_out;
                            cout << "Choose account" << endl;
                            cout << "1. USD account" << endl;
                            cout << "2. KH account" << endl;
                            cout << "3. Back" << endl;
                            cout << "[Option] = ";
                            cin >> option;
                            switch (option)
                            {
                            case 1:
                                if (cash_out / rate > bank.usd)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.usd -= cash_out / rate;
                                        cout << "You paid R" << cash_out << " from USD account." << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 2:
                                if (cash_out > bank.riel)
                                {
                                    cout << "Insufficient balance!" << endl;
                                }
                                else
                                {
                                    cout << "Enter password to confirm : ";
                                    cin >> passwordEnter;
                                    if (passwordEnter == passwordSet)
                                    {
                                        bank.riel -= cash_out;
                                        cout << "You paid R" << cash_out << " from KH account.;" << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong password!" << endl;
                                    }
                                    cout << "Press any key to see account : ";
                                    getch();
                                    bank.account();
                                }
                                break;
                            case 3:
                                break;
                            default:
                                cout << "Error!" << endl;
                                break;
                            }
                            break;
                        case 8:
                            break;
                        default:
                            break;
                        }
                        if (option != 8)
                        {
                            cout << "Press any key to continue : ";
                            getch();
                        }
                    } while (option != 8);
                    break;
                case 5:
                    do
                    {
                        system("cls");
                        cout << "___________________________________________________" << endl;
                        cout << "|                                                 |" << endl;
                        cout << "|                     Transfer                    |" << endl;
                        cout << "|_________________________________________________|" << endl;
                        cout << "|                        |                        |" << endl;
                        cout << "|   1. To own account    | 2. To another account  |" << endl;
                        cout << "|________________________|________________________|" << endl;
                        cout << "|                        |                        |" << endl;
                        cout << "|   3. To ATM            | 4. Back                |" << endl;
                        cout << "|________________________|________________________|" << endl;
                        cout << "[Option] = ";
                        cin >> option;
                        switch (option)
                        {
                        case 1:
                            do
                            {
                                system("cls");
                                cout << "1. USD => KH" << endl;
                                cout << "2. KH => USD" << endl;
                                cout << "3. Back" << endl;
                                cout << "[Option] = ";
                                cin >> option;
                                switch (option)
                                {
                                case 1:
                                    bank.transfer("usd->riel");
                                    break;
                                case 2:
                                    bank.transfer("riel->usd");
                                    break;
                                case 3:
                                    break;
                                default:
                                    break;
                                }
                                if (option != 3)
                                {
                                    cout << "Press any key to continue : ";
                                    getch();
                                }
                            } while (option != 3);
                            break;
                        case 2:
                            do
                            {
                                system("cls");
                                cout << "Choose account to transfer" << endl;
                                cout << "1. USD account" << endl;
                                cout << "2. KH account" << endl;
                                cout << "3. Back" << endl;
                                cout << "[Option] = ";
                                cin >> option;
                                switch (option)
                                {
                                case 1:
                                    bank.transfer("usd", receive);
                                    break;
                                case 2:
                                    bank.transfer("riel", receive);
                                    break;
                                case 3:
                                    break;
                                default:
                                    cout << "Error!" << endl;
                                    break;
                                }
                                if (option != 3)
                                {
                                    cout << "Press any key to continue : ";
                                    getch();
                                }
                            } while (option != 3);
                            break;
                        case 3:
                            do
                            {
                                system("cls");
                                cout << "Choose account to transfer" << endl;
                                cout << "1. USD account" << endl;
                                cout << "2. KH account" << endl;
                                cout << "3. Back" << endl;
                                cout << "[Option] = ";
                                cin >> option;
                                switch (option)
                                {
                                case 1:
                                    bank.transfer("usd", "ATM");
                                    break;
                                case 2:
                                    bank.transfer("riel", "ATM");
                                    break;
                                case 3:
                                    break;
                                default:
                                    cout << "Error!" << endl;
                                    break;
                                }
                                if (option != 3)
                                {
                                    cout << "Press any key to continue : ";
                                    getch();
                                }
                            } while (option != 3);
                            break;
                        case 4:
                            break;
                        default:
                            break;
                        }
                        if (option != 4)
                        {
                            cout << "Press any key to continue : ";
                            getch();
                        }
                    } while (option != 4);
                    break;
                case 6:
                    system("cls");
                    bank.setting();
                    break;
                case 7:
                    break;
                default:
                    cout << "Error!" << endl;
                    break;
                }
                if (option != 7)
                {
                    cout << "Press any key to continue : ";
                    getch();
                }
            } while (option != 7);
            break;
        case 4:
            system("cls");
            cout << green << ">>>>>>>>>>>>>>>>>>>>>>>>>>> Functinalities" << white << endl;
            cout << "_________________________________________________________________________________" << endl;
            cout << "|                      | Control the flow of all staff's data such as:          |" << endl;
            cout << "|                      | 1. Insert                                              |" << endl;
            cout << "|                      | 2. Display                                             |" << endl;
            cout << "| Staff Management     | 3. Search                                              |" << endl;
            cout << "|                      | 4. Update                                              |" << endl;
            cout << "|                      | 5. Save (To a text file)                               |" << endl;
            cout << "|                      | 6. Delete                                              |" << endl;
            cout << "|______________________|________________________________________________________|" << endl;
            cout << "|                      | Control the flow of all customers' data such as:       |" << endl;
            cout << "|                      | 1. Insert                                              |" << endl;
            cout << "|                      | 2. Display                                             |" << endl;
            cout << "| Customer Management  | 3. Search                                              |" << endl;
            cout << "|                      | 4. Update                                              |" << endl;
            cout << "|                      | 5. Save (To a text file)                               |" << endl;
            cout << "|                      | 6. Delete                                              |" << endl;
            cout << "|______________________|________________________________________________________|" << endl;
            cout << "|                      | This application is used as a mobile bank account      |" << endl;
            cout << "| BIU Mobile           | for users so as to be more convenient for other        |" << endl;
            cout << "|                      | payments in their daily lives.                         |" << endl;
            cout << "|______________________|________________________________________________________|" << endl;
            cout << "|                      | We are consumed to run a business on building          |" << endl;
            cout << "| About                | softwares for clients based on what they want such as  |" << endl;
            cout << "|                      | websites, mobile applications, and so on.              |" << endl;
            cout << "|______________________|________________________________________________________|" << endl;
            cout << endl;
            cout << green << ">>>>>>>>>>>>>>>>>>>>>>>>>>> About US" << white << endl;
            cout << "_____________________________________________________________________" << endl;
            cout << "|                       |                         |                 |" << endl;
            cout << "|      Developers       |          Major          |     Contact     |" << endl;
            cout << "|_______________________|_________________________|_________________|" << endl;
            cout << "|                       |                         |                 |" << endl;
            cout << "|     Hun Lihong        |  Software Engineering   |   088 438 8973  |" << endl;
            cout << "|     Hean Lyhong       |  Software Engineering   |   016 970 873   |" << endl;
            cout << "|     Kao Menghorn      |  Software Engineering   |   071 200 1000  |" << endl;
            cout << "|     Khin Sambath      |  Software Engineering   |   071 200 1000  |" << endl;
            cout << "|     Thoeun Wiphu      |  Software Engineering   |   010 813 330   |" << endl;
            cout << "|_______________________|_________________________|_________________|" << endl;
            cout << endl;
            break;
        case 5:
            cout << "Program is exitted." << endl;
            break;
        default:
            cout << "Error!" << endl;
            break;
        }
        if (option != 5)
        {
            cout << "Press any key to continue : ";
            getch();
        }
    } while (option != 5);
    return 0;
}