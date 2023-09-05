#include <iostream>
#include <vector>

using namespace std;

vector<bool> che(int n)
{
    // 1 사전작업
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    // 2 배수 삭제 - long long 
    for(long long i=2; i<=n; i++)
    {
        for(long long j = i*i; j<=n; j+=i)
        {
            isPrime[j] = false;
        }
    }

    return isPrime;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<bool> result = che(M);

    for(int i=N;i<=M;i++)
    {
        if(result[i])
        {
            cout << i << "\n";
        }
    }


    return 0;   
}