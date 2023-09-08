#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    int y = 7980;
    cout << y%15 << " " << y%28 << " " << y%19 << " ";
    */

    int e, s, m;
    cin >> e >> s >> m;

    int num = 1;
    int te = 1, ts = 1, tm = 1;
    while (true)
    {
        if (te == e && ts == s && tm == m)
        {
            cout << num;
            return 0;
        }

        te++;
        ts++;
        tm++;

        if(te>15)
        {
            te-=15;
        }

        if(ts>28)
        {
            ts-=28;
        }

        if(tm>19)
        {
            tm-=19;
        }

        num++;
    }

    return 0;
}