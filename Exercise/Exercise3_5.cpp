#include <iostream>
#include "Pizza.h"

using namespace std;

int main()
{
    Pizza<int>* pizza1 = new Pizza<int>;
    cout << "Enter the pizza diameter, company name, and weight: ";
    cin >> pizza1->tPizzaDiameter >> pizza1->strPizzaCompanyName >> pizza1->tPizzaWeight;

    cout << "Pizza Diameter: " << pizza1->tPizzaDiameter << endl;
    cout << "Pizza Company Name: " << pizza1->strPizzaCompanyName << endl;
    cout << "Pizza Weight: " << pizza1->tPizzaWeight << endl;

}