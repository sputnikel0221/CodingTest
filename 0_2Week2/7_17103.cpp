#include <iostream>
#include <vector>

using namespace std;

vector<bool> che(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i <= n; i++)
    {
        for (long long j = i * i; j <= n; j += i)
        {
            isPrime[j] = false;
        }
    }

    return isPrime;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<bool> e = che(1000000);

    while (n--)
    {
        int num;
        cin >> num;

        int count = 0;

        // 1. 중복을 방지하기 위해, 반까지만 감
        // 2. 2도 포함이므로 2부터 시작. (만약 홀수만이면 3부터 시작)
        for (int i = 2; i <= num / 2; i++)
        {
            if (e[i] && e[num - i])
            {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}