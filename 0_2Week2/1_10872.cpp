#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    if(N==0)
    {
        cout << 1;
        return 0
        ;
    }
    int fac = 1;
    for(int i=2;i<=N;i++)   
    {
        fac*=i;
    }
    cout << fac;

    return 0;   
}