#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int d = 2;
    while (n != 1)
    {
        if (n % d == 0)
        {
            n /= d;
            cout << d << "\n";
        }
        else
        {
            d++;
        }
    }

    return 0;
}