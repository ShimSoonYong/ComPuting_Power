#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float f = 3.14f;
    double d = 3.14;

    cout << "single precision floating point number : f = " << fixed << setprecision(20) << f << endl;
    cout << "double precision floating point number : d = " << fixed << setprecision(20) << d << endl;

    return EXIT_SUCCESS;
}
