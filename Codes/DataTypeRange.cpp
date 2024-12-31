#include <iostream>
#include <limits>
#include <cfloat>

using namespace std;

int main()
{
    // C style
    cout << "float min: " << FLT_MIN << endl;
    cout << "float max: " << FLT_MAX << endl;
    cout << "double min: " << DBL_MIN << endl;
    cout << "double max: " << DBL_MAX << endl;
    // C++ style
    cout << "float min: " << numeric_limits<float>::min() << endl;
    cout << "float max: " << numeric_limits<float>::max() << endl;
    cout << "double min: " << numeric_limits<double>::min() << endl;  
    cout << "double max: " << numeric_limits<double>::max() << endl;
}
