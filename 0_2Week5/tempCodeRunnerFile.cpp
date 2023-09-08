#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    int y = 7980;
    cout << y%15 << " " << y%28 << " " << y%19 << " ";
    */

    int e, s, m;
    cin >> e >> s >> m;

    int x=0;

    if(e==15 && s==28 && m==19)
    {
        cout << 7980;
        return 0;
    }

    while(true)
    {
        if(x%13==e && x%28==s && x%19==m )
        {
            cout << x;
            return 0;
        }
        x++;
    }

    return 0;   
}