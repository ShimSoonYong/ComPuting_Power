#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <iomanip>

using namespace std;

int main()
{
    double ex, g = 1, eps;

    try {
        do{
            g = g / 2;
            ex = g * 0.98 + 1;
            ex = ex - 1;
            cout << "g = " << scientific << setprecision(14) << g << "\tex = " << ex << endl;
            if ( ex > 0 ) eps = ex;
        }
        while ( ex > 0 );

        cout << "\nmachine epsilon = " << scientific << setprecision(14) << eps << endl;
        cout << "\nnumeric_limits::epsilon = " << scientific << setprecision(14) << numeric_limits<double>::epsilon() << endl;
    }
    catch (const exception &error) {
        cerr << error.what() << endl;
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
