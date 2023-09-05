#include <iostream>
#include <vector>

using namespace std;

vector<bool> che(int n)
{
    // 1부터 n까지 사용할거라 n+1 크기의 true로 초기화 한 벡터
    vector<bool> isPrime(n + 1, true);
    // 0과 1은 일단 소수가 아니다.
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                isPrime[i] = false;
            }
        }
    }

    return isPrime;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    vector<bool> result;
    result = che(1000);

    int count = 0;
    while (N--)
    {
        int n;
        cin >> n;

        if(result[n])
        {
            count++;
        }
    }

    cout << count;

    return 0;
}