#include <iostream>

using namespace std;

int main()
{
    double dist;

    cout << "마일로 거리를 입력해: ";
    cin >> dist;

    dist *= 1.60934;

    cout << "킬로미터로 하면: " << dist << "km 니까 야드파운드 말고 미터법을 써!" << endl;

}