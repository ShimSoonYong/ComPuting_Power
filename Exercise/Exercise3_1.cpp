#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string strFirstName, strLastName, strDesiredGPA;
    int age;

    cout << "English first name: ";
    getline(cin, strFirstName);
    cout << "English Last name: ";
    cin >> strLastName;
    cout << "Desired GPA? ";
    cin >> strDesiredGPA;
    cout << "Age: ";
    cin >> age;

    cout << "Name: " << strLastName << ", " << strFirstName << endl;
    cout << "GPA: " << "F" << endl;
    cout << "Age: " << age << endl;
}