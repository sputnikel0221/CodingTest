#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    // 초기화 및 선언
    int t[N + 1] = {
        0,
    };
    int p[N + 1] = {
        0,
    };
    int d[N + 1] = {
        0,
    };

    // 입력값
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
        cin >> p[i];
    }

    for (int i = N; i >= 1; i--)
    {   
        if(i+t[i] > N+1)    // 시간 상 할 수 없는 일이라면,
        {
            d[i] = d[i+1];  // 다음날의 일을 하도록 함. (다음날의 시간은??)
        }
        else
        {
            d[i] = max(d[i+1], p[i] + d[i+t[i]]);
        }
    }

    cout << d[1];
    return 0;
}