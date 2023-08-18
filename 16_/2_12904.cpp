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
        if(T[T.length()-1] == 'B')
        {
            T.erase(T.length()-1);
            reverse(T.begin(), T.end());
            //cout << "B : ";
        }
        else
        {
            T.erase(T.length()-1);
            //cout << "A : ";
        }

        //cout << "T : " << T << "\n";
    }

    //cout << S << " / " << T <<"\n";
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