#include <iostream>
#include <vector>
using namespace std;

vector<bool> che(int n)
{
    // 1 사전작업
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    // 2 배수제거
    for(long long i=2; i<=n;i++)
    {
        for(long long j=i*i; j<=n; j+=i)
        {
            isPrime[j] = false;
        }
    }

    return isPrime;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    vector<bool> result = che(1000000);

    while(true)
    {
        int n;
        cin >> n;

        if(n==0)
        {
            break;
        }

        //for(int i=3; i<=n;i++)
        for(int i=3; i<=n-3;i++)
        {
            if(result[i] && result[n-i])
            {
                cout << n << " = " << i << " + " << n-i << "\n";
                break;
            }

            if(i==n-3)
            {
                cout << "Goldbach's conjecture is wrong.\n";
            }
        }
    }
    

    return 0;   
}