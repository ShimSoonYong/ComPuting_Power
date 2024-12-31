class BaseClass
{
public:
    int PublicFunc();

protected:
    int ProtectedFunc();

private:
    int PrivateFunc();
};

// BaseClass 에서 상속받는 두 개의 클래스 선언
class DerivedClass1 : public BaseClass
{
    void foo()
    {
        PublicFunc();
        ProtectedFunc();
        PrivateFunc(); // 이것은 접근 불가능
    }
};

class DerivedClass2 : private BaseClass
{
    void foo()
    {
        PublicFunc();
        ProtectedFunc();
        PrivateFunc(); // 접근 불가능
    }
};

int main()
{
    DerivedClass1 derived_class1;
    DerivedClass2 derived_class2;
    derived_class1.PublicFunc();
    derived_class2.PublicFunc(); // private으로 들어가서 접근 불가능
}