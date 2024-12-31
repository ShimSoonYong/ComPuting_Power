class Base
{
    public:
        int Print();
        static int CountOf();
};

class Derived1 : private Base 
{
};

class Derived2 : public Derived1
{
    int ShowCount();
};

int Derived2::ShowCount()
{
    int cCount = ::Base::CountOf(); // 작동함

    cCount = this->CountOf(); // 불가능. Derived1이 Base를 상속받을 때 `private`을 사용했기 때문.

    return cCount;
};