#include <iostream>
#include "CandyBar.h"

using namespace std;

int main()
{
    CandyBar bars[3] = {
        {"HushBar", 20, 520},
        {"GanaBar", 15, 400},
        {"MashmellowBar", 5, 120}
    };
    
    for (int i = 0; i < 3; ++i) {
        cout << "CandyBar " << i + 1 << ": " << bars[i].brandName << ", " << bars[i].weight << ", " << bars[i].calories << endl;
    }
}