#include <iostream>
using namespace std;

enum Calc
{
    add = 1,
    sub = 2
};

void s_add();
void s_sub(int, int);

int main()
{
    // 1. enum값을 넣을 수 있다.
    Calc mode;
    switch (mode)
    {
    }

    // 2. cin으로는 절대 enum값을 받을 수 없다.
    // cin >> mode // cin >> (int)mode
    // 정수를 그냥 받아야만 한다. //scanf("d", &mode);
    int int_mode;
    cin >> int_mode;
    
    // 3. enum은 숫자이다. 문자열을 받을 수가 없다.
    // 그냥 숫자를 다른 모양으로 쓰는 것 뿐이다. (상수)
    switch (int_mode)
    {
    case add:
        cout << "added";
        break;

    case sub:
        cout << "subed";
        break;

        return 0;
    }

}

void s_add();
void s_sub(int a, int b)
{
    cout << a - b;
}
