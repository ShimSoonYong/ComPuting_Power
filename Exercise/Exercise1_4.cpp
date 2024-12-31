#include <iostream>

void DayHourMinuteSec(int second)
{
    int minute, hour, day;

    minute = second / 60;
    hour = minute / 60;
    day = hour / 24;
    second %= 60;

    minute -= hour * 60;
    hour -= day * 24;

    std::cout << "Time: " << day << ":" << hour << ":" << minute << ":" << second << std::endl;

}

int main()
{
    int second;

    std::cout << "Time by second: ";
    std::cin >> second;
    DayHourMinuteSec(second);
}