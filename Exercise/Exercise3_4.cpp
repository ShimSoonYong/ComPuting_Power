#include <iostream>
#include "Pizza.h"

using namespace std;

int main(){
    Pizza<int> pizza1;
    cout << "Enter the pizza company name, diameter, and weight: ";
    cin >> pizza1.strPizzaCompanyName >> pizza1.tPizzaDiameter >> pizza1.tPizzaWeight;

    cout << "Pizza Company Name: " << pizza1.strPizzaCompanyName << endl;
    cout << "Pizza Diameter: " << pizza1.tPizzaDiameter << endl;
    cout << "Pizza Weight: " << pizza1.tPizzaWeight << endl;

    return 0;
}