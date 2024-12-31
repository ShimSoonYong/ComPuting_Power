# 클래스 (C++)

`class` 키워드는 클래스 자료형을 선언하거나 클래스 자료형의 객체를 정의한다.

## 문법

```cpp
[템플릿 지정]
class [선언 지정] [태그(클래스명) [: 부모 리스트]]
{
    멤버 리스트
} [선언자들]; //클래스를 정의하자마자 객체 생성
[ class ] 태그 선언자들; //클래스 정의 후 객체 생성
```

#### 매개변수
*탬플릿 지정*
- 선택적 템플릿 지정.

*class*
- 키워드

*선언 지정*
- 선택적 저장공간 클래스 지정이라고 한다.
    - 원문: *ms-decl-spec*, Optional storage-class specification. For more information, refer to the <font color='skyblue'>__declspec</font> keyword.

*태그*
- 클래스에 주어진 자료형 이름이다. 
- 클래스의 스코프 내에서 예약어가 된다.
- 태그는 선택사항이다. 
    - 만약 생략될 경우, 익명 클래스가 선언된다.

*부모 리스트*
- 이 클래스가 멤버들을 도출할 클래스들이나 구조체들의 선택적 리스트이다.
- 각 부모 클래스나 구조체의 이름들은 접근 지정자(`public`, `private`, `protected`)와 `virtual` 키워드로 선행될 수 있다. 

*멤버 리스트*
- 클래스 멤버들의 리스트.

*선언자들*
- 하나 이상의 그 클래스 자료형을 가진 선언자들의 이름 리스트.
- 만약 클래스의 모든 데이터 멤버들이 `public`일 경우 선언자들은 초기화를 포함할 수 있다.
    - 이는 구조체에서 보다 일반적으로 사용된다. 구조체의 데이터 멤버들은 기본적으로 `public`이다. 클래스는 아니다. 

```cpp
#include <iostream>
#include <string>
using namespace std;

class dog
{
    public:
        dog()
        {
            _legs = 4;
            _bark = true;
        }

        void setDogSize(string dogSize)
        {
            _dogsize = dogSize;
        }

        virtual void setEars(string type)
        {
            _earType = type;
        }
    
    private:
        string _dogsize, _earType;
        int _legs;
        bool _bark;
};

class breed : public dog
{
    public:
        breed(string color, string size)
        {
            _color = color;
            setDogSize(size);
        }

        string getColor()
        {
            return _color;
        }

        void setEars(string length, string type)
        {
            _earLength = length;
            _earType = type;
        }
    
    protected:
        string _color, _earLength, _earType;
};

int main()
{
    dog mongrel;
    string col;
    cout << "Enter a color for a dog. " << endl;
    cin >> col;
    breed labrador(col, "large");
    mongrel.setEars("pointy");
    labrador.setEars("long", "floppy");
    cout << "Cody is a " << labrador.getColor() << " labrador" << endl;
}
```

## 멤버 접근 제어
클래스의 멤버들은 멤버 리스트에 선언된다. 클래스의 멤버 리스트는 접근 지정자로 알려진 `private`, `protected`, 그리고 `public` 구역들에 키워드를 통해 나눠질 수 있다. 콜론 `:`이 접근 지정자에 따라와야 한다. 

접근 제어는 `private`의 구현 세부사항으로부터 `public`의 인터페이스와, 자식 클래스에서만 쓰일 `prtected` 멤버들을 분리한다. 접근 지정자는 다음 접근 지정자를 만나기 전까지 지정자 다음에 선언된 모든 멤버들에게 적용된다. 

```cpp
class Point
{
    public:
        Point(int, int); // public 생성자
        Point(); // public default 생성자
        int &x(int); // public 접근자 선언
        int &y(int); // public 접근자 선언
    
    private: // private 상태 변수들 선언
        int _x;
        int _y;
    
    protected: // 오직 자식 클래스들만을 위한 protected 함수 선언
        Point ToWindowCorrds();

};
```
클래스의 기본 접근은 `private`이고, 구조체나 공용체에선 `public`이다. 클래스에서의 접근 지정자들은 어떤 순서로든 얼마든지 사용될 수 있다. 

|접근 유형|의미|
|----|----|
|`private`|이걸로 선언된 클래스 멤버들은 그 클래스의 멤버함수나 프렌드에서만 사용될 수 있다.
|`protected`|이걸로 선언된 클래스 멤버들은 그 클래스의 멤버함수와 프렌드에 사용될 수 있고, 또한 지식 클래스에서도 사용될 수 있다.
|`public`|어떤 함수에서든 사용될 수 있다.|

### 자식 클래스에서의 접근 제어
두 개의 요인이 부모 클래스의 어떤 멤버들이 자식 클래스에서 접근 가능할지를 제아한다. 그리고 그 요인들은 자식 클래스의 상속받은 멤버들에 대한 접근도 제어한다.
- 요인 1: 자식 클래스가 부모 클래스를 `public` 접근 지정자로 선언했는지 아닌지.
- 요인 2: 부모 클래스에서 멤버에 대한 접근이 무엇인지(`public`, `private`, `protected`).

|`private`|`protected`|`public`|
|---------|-----------|--------|
|어떤 자식의 접근에도 항상 접근 불가능|`private` 상속을 사용했다면 `private`|`private` 상속을 사용했다면 `private`|
| |`protected` 상속을 사용했다면 `protected`|`protected` 상속을 사용했다면 `protected`|
| |`public` 상속을 사용했다면 `protected`|`public` 상속을 사용했다면 그대로 `public`|

예시:
```cpp
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
```

부모 클래스 접근 지정자 없이도 자식 클래스를 선언할 수 있다. 그러한 경우, 상속 내용은 클래스 선언이 `class` 키워드를 통해 이뤄질 경우 `private`로 취급된다. 반대로 선언이 `struct` 키워드로 이뤄졌으면 `public`으로 취급된다. 공용체 `union`은 상속을 받을 수 없다. 

## 접근 제어와 정적 멤버

부모 클래스를 `private`로 지정할 경우, 비-정적 객체들에 대해서만 영향을 미친다. `public` 정적 객체들은 자식 클래스에서 여전히 접근 가능하다. 하지만, 부모 클래스의 멤버들에 포인터, 참조, 또는 객체를 통해 접근하는 것은 접근 제어를 다시 적용하는 형 변환을 요구할 수 있다. 

```cpp
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
```
위의 코드에서, 접근 제어는 `Derived2`에 대한 포인터에서 `Base`에 대한 포인터로 변환하는 것을 금지한다. `this` 포인터는 암묵적으로 Derived2 *(포인터) 자료형을 의미한다. 그러한 변환은 허용되지 않는데, 왜냐하면 `Base`는 `Derived2` 클래스에게 있어서 `private` 간접 부모 클래스이기 때문이다. 이미 `private`로 들어간 부모 클래스 자료형으로 변환하는 것은 바로 밑의 자식 클래스에 대한 포인터들에게만 허용 가능하다. 그래서 `Derived1 *` 자료형의 포인터들은 `Base *` 자료형으로 변환될 수 있다. 

`CountOf` 함수의 명시적 호출, 즉 포인터, 참조, 또는 그것을 선택하는 객체 없이 호출하는 것은, 형 변환을 나타내지 않는다.

## 프렌드
어떤 경우엔, 클래스의 멤버가 아닌 함수나 분리된 클래스의 모든 멤버들에 대해 멤버 수준의 접근을 할 수 있게 하는 것은 유용하다. 이 자유로운 함수와 클래스들은 `friend` 키워드로 표시되는 *프렌드*로 알려져 있다. 클래스 정의문만이 프렌드에 해당하는 게 무엇인지를 선언할 수 있다. 어떤 함수나 클래스도 그 자체로 다른 클래스의 프렌드로 선언할 수 있다. 클래스 정의의 경우, `friend` 키워드와 비멤버 함수 또는 다른 클래스의 이름을 사용하여 해당 함수나 클래스가 자신의 클래스의 `private` 및 `protected` 멤버에 접근할 수 있도록 허용한다.

### 문법
`friend` 함수 선언문
`friend` 함수 정의문
`friend` 명확히 지정된 자료형 지정자
`friend` 단순 자료형 지정자
`friend` 지료형 이름 지정자
- 템플릿 클래스에서 `typename`을 사용해 특정 타입을 `friend`로 선언할 때 사용
    - 예: `friend typename T;`
