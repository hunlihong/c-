#include <iostream>
#include <iomanip>
using namespace std;

class Person
{
private:
    string id, name, gender;

public:
    Person() {}
    Person(string id, string name, string gender)
    {
        this->id = id;
        this->name = name;
        this->gender = gender;
    }
    void input()
    {
        cout << "Input ID=";
        cin >> id;
        cout << "Input name=";
        cin >> name;
        cout << "Input gender=";
        cin >> gender;
    }
    void display()
    {
        cout << "=============================" << endl;
        cout << "ID = " << id << endl;
        cout << "Name = " << name << endl;
        cout << "Gender = " << gender << endl;
    }
};
int main()
{
    system("cls");
    int n;
    cout << "How many people do you want to input? [Answer] = ";
    cin >> n;
    Person person[n];
    for (int i = 0; i < n; i++)
    {
        person[i].input();
    }
    for (int i = 0; i < n; i++)
    {
        person[i].display();
    }
    return 0;
}