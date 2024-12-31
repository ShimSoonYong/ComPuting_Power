#include <cstdio>
#include <typeinfo>

#define INFO(v1, v2) std::printf("%s(%s, %s)\n", __FUNCTION__, typeid(v1).name(), typeid(v2).name());

void sum(char c1, char c2) { INFO(c1, c2); }
void sum(short s1, short s2) { INFO(s1,s2); }
void sum(int n1, int n2) { INFO(n1,n2);}
void sum(float f1, float f2) { INFO(f1,f2);}
void sum(double d1, double d2) { INFO(d1,d2); }

int main()
{
    char c1 = 1, c2 = 2;
    short s1 = 1, s2 = 2;
    float f1 = 1, f2 = 2;

    sum(c1, c2);
    sum(s1, s2);
    sum(f1, f2);

    sum(5, 10);
    sum(1.2, 3.4);

    return 0;
}
