#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    string ab = a+b;
    string cd = c+d;

    cout << stoll(ab) + stoll(cd);

    return 0;   
}