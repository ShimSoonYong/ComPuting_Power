# 함수(C++)

함수란:
- 어떤 연산을 수행하는 코드 블록이다. 
- 함수는 호출자가 함수에 인수를 전달할 수 있도록 입력 매개변수를 선택적으로 정의할 수 있다. 
- 함수는 출력으로 어떤 값을 선택적으로 반환할 수 있다.
- 함수는 흔히 쓰이는 연산들을 하나의 재사용 블록에 캡슐화하는 데에 유용하다.
    - 함수가 하는 동작을 명확히 기술하는 이름을 쓰는 것이 이상적이다.

아래의 함수는 호출자에서 두 개의 정수를 받아 합계를 반환한다.
```C++
int sum(int a, int b)
{
    return a + b;
}
```

함수는 프로그램의 어떤 곳에서든 적용 또는 *호출*될 수 있다. 함수에 전달된 값들은 *인수*라고 하며, 인수의 자료형은 함수 정의에서의 매개변수 자료형에 부합해야 한다.

```C++
int main()
{
    int i = sum(10, 32);
    int j = sum(i, 66);
    cout << "The value of j is" << j << endl;//The value of j is 108
}
```

함수의 길이에 실제적인 한계는 없지만, 좋은 설계는 하나의 잘 정의된 작업만을 수행하는 함수를 목표로 한다. 복잡한 알고리즘은 가능한 한 이해하기 쉬운 단순한 함수로 쪼개져야 한다.

클래스 스코프에서 정의된 함수는 멤버 함수라고 불린다. 다른 언어와는 달리 C++에선 함수가 네임스페이스 스코프에서 정의될 수 있다(암묵적인 전역 네임스페이스도 포함). 그런 함수들은 *자유 함수* 또는 *비-멤버 함수*라고 불리며, 표준 라이브러리에서 널리 사용된다(std 등).

함수들은 *오버로딩*될 수 있다. 오버로딩은 다른 버전의 함수들이 매개변수의 자료형이나 개수가 다를 경우 같은 이름을 공유하는 것을 의미한다.

## 함수 선언 부분들
최소한의 함수 *선언*은 컴파일러에게 더 많은 지시를 내리는 선택적 키워드와 함께하는, 반환 자료형, 함수 이름, 그리고 매개변수 리스트(비어있을 수도 있음)이다.

```C++
int sum(int a, int b);
```

함수 정의는 선언에 더해 중괄호 사이의 모든 코드인 *몸체* 부분으로 구성된다.

```C++
int sum(int a, int b)
{
    return a + b;
}
```
세미콜론이 따라가는 함수 선언은 프로그램의 여러 곳에서 나타날 수 있다. 선언문은 함수의 그 어떤 호출 전에 선행하여 각 번역 단위에서 나타나야 한다. 함수 정의문은 단일 정의 규칙(One Definition Rule, ODR)에 따라 프로그램에서 오직 한 번 등장해야 한다.

함수 선언에서 요구되는 부분들은:
1. 반환 자료형: 함수가 반환할 값의 자료를 지정하거나, 값이 반환되지 않을 경우 `void`로 지정한다. C++11에선 컴파일러가 자료형을 반환문에서 추론하도록 지시하는 `auto`도 유효한 반환 자료형이다. C++14에선 `decltype(auto)`도 허용된다.

2. 함수명: 문자나 언더스코어(_)로 시작해야 하고, 공백을 포함할 수 없다. 일반적으로, 표준 라이브러리 함수명들에서 앞쪽의 언더스코어들은 프라이빗 멤버 함수이거나, 사용자의 코드에서 사용되지 않도록 설계된 비-멤버 함수이다.

3. 매개변수 리스트: 괄호로 묶고, 콤마로 구분한다. 0개 이상의 매개변수로 구성되며, 각 매개변수는 자료형을 지정해야 한다. 매개변수 이름은 선택적으로 지정할 수 있으며, 함수 내부에서 그 이름으로 접근할 수 있다.

### 함수 선언의 선택적 부분들:

1. `constexpr`: 컴파일 시간에 계산될 수 있는 상수값이 함수의 반환값임을 지시한다.

```C++
constexpr float exp(float x, int n)
{
    return n == 0 ? 1:
        n % 2 == 0 ? exp(x * x, n / 2):
        exp(x * x, (n - 1) / 2) * x;
};
```

2. `extern` 또는 `static`: 함수의 연결 지정
- `extern`은 다른 번역 단위에서 정의된 함수나 변수를 사용할 수 있도록 선언한다. 다른 파일의 함수나 변수도 참조할 수 있다.
- `static`은 선언된 함수나 변수가 그것의 번역 단위 내부에서만 접근 가능하도록 제한한다. 네임스페이스 충돌 방지에 유용하다.

```C++
//C 연결과 함께 printf 선언하기
extern "C" int printf(const char *fmt, ...);
```

3. `inline`: 컴파일러에게 함수의 호출을 함수의 코드 자체로 대체할 것을 지시한다. 인라이닝은 코드에서 함수가 빨리 실행되어야 하거나 성능에 핵심적인 부분에서 반복적으로 호출될 때 성능을 향상시킬 수 있다.

```C++
inline double Account::GetBalance()
{
    return balance;
}
```

4. `noexcept` 표현식: 함수가 예외를 던지는지를 지정한다. `noexcept`가 붙은 함수가 예외를 던지면 프로그램이 강제 종료된다. 
- 기본 문법: `void foo() noexcept(condition);`


```C++
#include <type_traits> // std::is_pod 사용을 위해 필요

template <typename T>
T copy_object(T& obj) noexcept(std::is_pod<T>) {
    // 함수 정의: POD 타입일 때만 noexcept 적용
}
```

5. 함수가 `const`인지 `volatile`인지 지정하는 cv-한정자. 멤버함수만 해당.
- `const` 한정자:
    - 멤버 함수가 객체의 상태를 변경하지 않는다.
    - `const` 멤버 함수는 객체의 멤버 변수 값을 수정하거나 가변적이지 않은 변수를 변경할 수 없다.
    - `const` 객체에서 비-`const` 함수를 호출할 수 없다.
- `volatile` 한정자:
    - 멤버 함수가 `volatile` 객체에서 호출될 수 있음을 나타낸다.
    - `volatile`은 객체가 외부 요인에 의해 변경될 수 있음을 의미한다.

```C++
class Example {
public:
    void regular_function();             // 일반 멤버 함수
    void const_function() const;        // const 멤버 함수
    void volatile_function() volatile;  // volatile 멤버 함수
    void const_volatile_function() const volatile; // const와 volatile 동시 적용
};
```
6. `virtual`, `override`, `final`
- **`virtual`**: 파생 클래스에서 함수가 재정의될 수 있음을 지정한다.  
- **`override`**: 파생 클래스에서 해당 함수가 기반 클래스의 `virtual` 함수를 재정의하고 있음을 명시한다.  
- **`final`**: 함수가 더 이상 다른 파생 클래스에서 재정의될 수 없음을 지정한다.  

```cpp
#include <iostream>

class Base {
public:
    virtual void show() const { // virtual로 선언
        std::cout << "Base::show()" << std::endl;
    }
    virtual void info() const final { // final: 재정의 불가
        std::cout << "Base::info()" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() const override { // override: Base의 show 재정의
        std::cout << "Derived::show()" << std::endl;
    }

    // void info() const override; // 오류: info는 final로 선언됨.
};

int main() {
    Base* basePtr = new Derived();
    basePtr->show(); // Derived::show() 출력
    basePtr->info(); // Base::info() 출력

    delete basePtr;
    return 0;
}
```

7. `static` 멤버 함수
- `static` 키워드를 멤버 함수에 적용하면, 해당 함수는 클래스의 객체 인스턴스와 연관되지 않는다.  
  즉, 객체 없이도 호출할 수 있으며, 멤버 변수에 접근할 수 없다(단, `static` 멤버 변수에는 접근 가능).

```cpp
#include <iostream>

class Math {
public:
    static int add(int a, int b) { // static 함수
        return a + b;
    }
};

int main() {
    std::cout << "3 + 4 = " << Math::add(3, 4) << std::endl; // 객체 없이 호출 가능
    return 0;
}
```

8. `ref-qualifier`
- **(비-정적 멤버 함수만 해당)**  
  `ref-qualifier`는 컴파일러가 함수 오버로드 시 어떤 함수 버전을 선택할지 지정하는 데 사용된다.  
  - **`&`**: 멤버 함수가 **lvalue** 참조로 호출될 때만 선택.  
  - **`&&`**: 멤버 함수가 **rvalue** 참조로 호출될 때만 선택.

```cpp
#include <iostream>

class Example {
public:
    void show() & { // lvalue 참조에서 호출
        std::cout << "Called on lvalue" << std::endl;
    }

    void show() && { // rvalue 참조에서 호출
        std::cout << "Called on rvalue" << std::endl;
    }
};

int main() {
    Example obj;
    obj.show();       // "Called on lvalue"

    Example().show(); // "Called on rvalue"
    return 0;
}
```

---

## 함수에서 복수의 값 반환하기
여러 방법이 있다.

1. 값들을 클래스나 구조체 객체로 감싼다.
- 호출 전에 클래스나 구조체 정의를 해야 한다.

```cpp
#include <string>
#include <iostream>

using namespace std;

struct S
{
    string name;
    int num;
};

S g()
{
    string t{ "hello" };
    int u{ 42 };
    return { t, u };
}

int main()
{
    S s = g();
    cout << s.name << " " << s.num << endl;
    return 0;
}
```

2. `std::tuple`이나 `std::pair` 객체를 반환한다.

```cpp
#include <tuple>
#include <string>
#include <iostream>

using namespace std;

tuple<int, string, double> f()
{
    int i{ 108 };
    string s{ "Some text" };
    double d{ .01 };
    return { i,s,d };
}

int main()
{
    auto t = f();
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;

    // --or--

    int myval;
    string myname;
    double mydecimal;
    tie(myval, myname, mydecimal) = f();
    cout << myval << " " << myname << " " << mydecimal << endl;

    return 0;
}
```

## 함수 포인터
C++은 C 언어와 같은 방식의 함수 포인터를 지원한다. 하지만 더 자료형에 안전한 대체재가 함수 객체에 사용된다. 

함수 포인터 자료형을 반환하는 함수를 선언한다면 함수 포인터 자료형의 별칭으로 `typedef`를 사용할 것이 권장된다. 예를 들어:

```cpp
typedef int (*fp)(int);
fp myFunction(char* s);
```
만약 이렇게 되지 않는다면, 함수 선언을 위한 적절한 문법은 식별자를 함수명과 인수 리스트로 대체함으로써 함수 포인터를 위한 선언문 문법으로부터 추론되어야 할 수 있다.

```cpp
int (*myFunction(char* s))(int);
```
이는 바로 전의 `typedef`를 사용한 선언과 동치이다.