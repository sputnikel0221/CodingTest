#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int c;

    while(b!=0)
    {
        c = a%b;
        a=b;
        b=c;
    }
    return a;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int x = gcd(a, b);
    int y = a * b / x;

    cout << x << "\n" << y;
    

    return 0;   
}