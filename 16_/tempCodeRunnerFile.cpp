#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S, T;
    cin >> S >> T;

    while(S.length() != T.length())
    {
        T.erase(T.length()-1);
        if(T[T.length()-1] == 'B')
        {
            reverse(T.begin(), T.end());
        }
    }

    if(S==T)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;   
}