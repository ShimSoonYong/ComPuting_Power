#include <iostream>

using namespace std;

int main()
{
    int ntall;
    const int nCM2M = 100;

    cout << "Input your height as cm: ";
    cin >> ntall;

    cout << ntall / nCM2M << "m " << ntall % nCM2M << "cm" << endl;

}