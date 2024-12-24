#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;
long n_staff = 0;
int n_book = 0;
int id;

void login()
{
    string username, password;
login:
    system("cls");
    cout << ">>>>>>>>>> Login Form <<<<<<<<<<" << endl;
    cout << "Enter username = ";
    getline(cin, username);
    cout << "Enter password = ";
    getline(cin, password);
    if (username == "Nov Dararak" && password == "Rak Graphics")
    {
        cout << "Login successfully. Press any key to continue : ";
        getch();
    }
    else
    {
        cout << "Login failed." << endl;
        cout << "Press any key to login again : ";
        getch();
        goto login;
    }
}
class Staff
{
private:
    int id, age;
    string name, contact, position;
    char gender;
    float salary;

public:
    void input()
    {
        cout << "----------------------------------" << endl;
        cout << "Input ID = ";
        cin >> id;
        cout << "Input name = ";
        cin.ignore();
        getline(cin, name);
        cout << "Input gender = ";
        cin >> gender;
        cout << "Input age = ";
        cin >> age;
        cout << "Input contact = ";
        cin >> contact;
        cout << "Input position = ";
        cin >> position;
        cout << "Input salary($) = ";
        cin >> salary;
    }
    void output()
    {
        cout << "----------------------------------" << endl;
        cout << "ID = " << id << endl;
        cout << "Name = " << name << endl;
        cout << "Gender = " << gender << endl;
        cout << "Age = " << age << endl;
        cout << "Contact = " << contact << endl;
        cout << "Position = " << position << endl;
        cout << "Salary($) = " << salary << endl;
    }
    int getID()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    char getGender()
    {
        return gender;
    }
    int getAge()
    {
        return age;
    }
    string getContact()
    {
        return contact;
    }
    string getPosition()
    {
        return position;
    }
    float getSalary()
    {
        return salary;
    }
};
class Book
{
protected:
    int id, year;
    string title, author;
    float price;
    string customer;

public:
    void input()
    {
        cout << "----------------------------------" << endl;
        cout << "Input book ID = ";
        cin >> id;
        cout << "Input book title = ";
        cin.ignore();
        getline(cin, title);
        cout << "Input book author = ";
        getline(cin, author);
        cout << "Input year book release = ";
        cin >> year;
        cout << "Input book price = ";
        cin >> price;
    }
    void output()
    {
        cout << "----------------------------------" << endl;
        cout << "Book ID = " << id << endl;
        cout << "Book title = " << title << endl;
        cout << "Book author = " << author << endl;
        cout << "Release year = " << year << endl;
        cout << "Price($) = " << price << endl;
    }
    int getID()
    {
        return id;
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    int getYear()
    {
        return year;
    }
    float getPrice()
    {
        return price;
    }
    string getCustomer()
    {
        return customer;
    }
    void setCustomer(string customer)
    {
        this->customer = customer;
    }
};
struct Sta
{
    void display(Staff staff[])
    {
        for (int i = 0; i < n_staff; i++)
        {
            staff[i].output();
        }
    }
    void search(Staff staff[])
    {
        bool found = false;
        cout << "Input ID to see data = ";
        cin >> id;
        for (int i = 0; i < n_staff; i++)
        {
            if (id == staff[i].getID())
            {
                found = true;
                staff[i].output();
            }
        }
        if (found == false)
        {
            cout << "Not found." << endl;
        }
    }
    void update(Staff staff[])
    {
        bool found = false;
        cout << "Input ID to update = ";
        cin >> id;
        for (int i = 0; i < n_staff; i++)
        {
            if (id == staff[i].getID())
            {
                found = true;
                staff[i].input();
                cout << "Update is done." << endl;
            }
        }
        if (found == false)
        {
            cout << "Not found." << endl;
        }
    }
    void deleted(Staff staff[])
    {
        bool found = false;
        cout << "Input ID to delete = ";
        cin >> id;
        for (int i = 0; i < n_staff; i++)
        {
            if (id == staff[i].getID())
            {
                found = true;
                for (int j = 0; j < n_staff - 1; j++)
                {
                    staff[j] = staff[j + 1];
                }
                n_staff--;
                cout << "Delete is done." << endl;
            }
        }
        if (found == false)
        {
            cout << "Not found." << endl;
        }
    }
    void save(Staff staff[])
    {
        char save;
        cout << "Do you want to save? (Y/N) = ";
        cin >> save;
        if (save == 'Y' || save == 'y')
        {
            fstream file;
            file.open("staff.txt", ios::out);
            for (int i = 0; i < n_staff; i++)
            {
                file << "----------------------------------" << endl;
                file << "ID = " << staff[i].getID() << endl;
                file << "Name = " << staff[i].getName() << endl;
                file << "Gender = " << staff[i].getGender() << endl;
                file << "Age = " << staff[i].getAge() << endl;
                file << "Contact = " << staff[i].getContact() << endl;
                file << "Position = " << staff[i].getPosition() << endl;
                file << "Salary($) = " << staff[i].getSalary() << endl;
                file.close();
                cout << "Save is done." << endl;
            }
        }
        else
        {
            return;
        }
    }
};
struct Shop
{
    void display(Book book[])
    {
        for (int i = 0; i < n_book; i++)
        {
            book[i].output();
        }
    }
    void search(Book book[])
    {
        bool found = false;
        cout << "Input ID to see data = ";
        cin >> id;
        for (int i = 0; i < n_book; i++)
        {
            if (id == book[i].getID())
            {
                found = true;
                book[i].output();
            }
        }
        if (found == false)
        {
            cout << "Not found." << endl;
        }
    }
    void update(Book book[])
    {
        bool found = false;
        cout << "Input ID to update = ";
        cin >> id;
        for (int i = 0; i < n_book; i++)
        {
            if (id == book[i].getID())
            {
                found = true;
                book[i].input();
                cout << "Update is done." << endl;
            }
        }
        if (found == false)
        {
            cout << "Not found." << endl;
        }
    }
    void deleted(Book book[])
    {
        bool found = false;
        cout << "Input ID to delete = ";
        cin >> id;
        for (int i = 0; i < n_book; i++)
        {
            if (id == book[i].getID())
            {
                found = true;
                for (int j = 0; j < n_book - 1; j++)
                {
                    book[j] = book[j + 1];
                }
                n_book--;
                cout << "Delete is done." << endl;
            }
        }
        if (found == false)
        {
            cout << "Not found." << endl;
        }
    }
    void sell(Book book[])
    {
        bool found = false;
        string customer;
        cout << "Input ID to find book = ";
        cin >> id;
        for (int i = 0; i < n_book; i++)
        {
            if (id == book[i].getID())
            {
                found = true;
                cout << "Book is found." << endl;
                cout << "Input customer's name = ";
                cin.ignore();
                getline(cin, customer);
                book[i].setCustomer(customer);
                cout << "----------------------------------" << endl;
                cout << "Book with ID = " << book[i].getID() << " is sold to " << book[i].getCustomer() << endl;
                for (int j = i; j < n_book - 1; j++)
                {
                    book[j] = book[j + 1];
                }
                n_book--;
            }
        }
        if (found == false)
        {
            cout << "Not found." << endl;
        }
    }
    void borrow(Book book[])
    {
        bool found = false;
        int day;
        string customer;
        cout << "Input ID to find book = ";
        cin >> id;
        for (int i = 0; i < n_book; i++)
        {
            if (id == book[i].getID())
            {
                found = true;
                cout << "Book is found." << endl;
                cout << "How many days will a book be borrowed? = ";
                cin >> day;
                if (day > 0 && day <= 7)
                {
                    cout << "Input customer's name = ";
                    cin.ignore();
                    getline(cin, customer);
                    book[i].setCustomer(customer);
                    cout << "----------------------------------" << endl;
                    cout << "Book with ID = " << book[i].getID() << " is borrowed by " << book[i].getCustomer() << endl;
                    for (int j = i; j < n_book - 1; j++)
                    {
                        book[j] = book[j + 1];
                    }
                    n_book--;
                }
                else
                {
                    cout << "Borrow is taken for only 1-7 days." << endl;
                }
            }
        }
        if (found == false)
        {
            cout << "Not found." << endl;
        }
    }
    void save(Book book[])
    {
        char save;
        cout << "Do you want to save? (Y/N) = ";
        cin >> save;
        if (save == 'Y' || save == 'y')
        {
            fstream file;
            file.open("Shop.txt", ios::out);
            for (int i = 0; i < n_book; i++)
            {
                file << "----------------------------------" << endl;
                file << "ID = " << book[i].getID() << endl;
                file << "Title = " << book[i].getTitle() << endl;
                file << "Author = " << book[i].getAuthor() << endl;
                file << "Year = " << book[i].getYear() << endl;
                file << "Price = " << book[i].getPrice() << endl;
                file.close();
                cout << "Save is done." << endl;
            }
        }
        else
        {
            return;
        }
    }
};
void setting()
{
    cout << "==============================" << endl;
    cout << "Developed by Nov Dararak." << endl;
    cout << "Username = Nov Dararak" << endl;
    cout << "Password = Rak Graphics" << endl;
}
int main()
{
    // login();
    system("cls");
    int option;
    Staff staff[100];
    Book book[100];
    Sta sta;
    Shop shop;
    cout << fixed << showpoint << setprecision(2);
    do
    {
        cout << "1. Staff management" << endl;
        cout << "2. Shop management" << endl;
        cout << "3. About" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose = ";
        cin >> option;
        switch (option)
        {
        case 1:
            do
            {
                cout << "1. Insert" << endl;
                cout << "2. Display" << endl;
                cout << "3. Search" << endl;
                cout << "4. Update" << endl;
                cout << "5. Delete" << endl;
                cout << "6. Save" << endl;
                cout << "7. Exit" << endl;
                cout << "Choose = ";
                cin >> option;
                switch (option)
                {
                case 1:
                    staff[n_staff].input();
                    n_staff++;
                    cout << "Insert is done." << endl;
                    break;
                case 2:
                    sta.display(staff);
                    break;
                case 3:
                    sta.search(staff);
                    break;
                case 4:
                    sta.update(staff);
                    break;
                case 5:
                    sta.deleted(staff);
                    break;
                case 6:
                    sta.save(staff);
                    break;
                case 7:
                    break;
                default:
                    break;
                }
            } while (option != 7);
            break;
        case 2:
            do
            {
                cout << "1. Insert" << endl;
                cout << "2. Display" << endl;
                cout << "3. Search" << endl;
                cout << "4. Update" << endl;
                cout << "5. Delete" << endl;
                cout << "6. Sell" << endl;
                cout << "7. Borrow" << endl;
                cout << "8. Save" << endl;
                cout << "9. Exit" << endl;
                cout << "Choose = ";
                cin >> option;
                switch (option)
                {
                case 1:
                    book[n_book].input();
                    n_book++;
                    cout << "Insert is done." << endl;
                    break;
                case 2:
                    shop.display(book);
                    break;
                case 3:
                    shop.search(book);
                    break;
                case 4:
                    shop.update(book);
                    break;
                case 5:
                    shop.deleted(book);
                    break;
                case 6:
                    shop.sell(book);
                    break;
                case 7:
                    shop.borrow(book);
                    break;
                case 8:
                    shop.save(book);
                    break;
                case 9:
                    break;
                default:
                    break;
                }
            } while (option != 9);
            break;
        case 3:
            setting();
            break;
        case 4:
            cout << "You exit the program." << endl;
            break;
        default:
            cout << "Error." << endl;
            break;
        }
    } while (option != 4);
    return 0;
}