#include <iostream>
using namespace std;

int N, M;

bool connection[501][501];  // i로부터 j를 갈 수 있는가

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // 1 직접 연결된 점들을 true
    while (M--) 
    {
        int a, b;
        cin >> a >> b;
        connection[a][b] = true;
    }

    // 2 직접 연결되지 않았어도, k를 통해서라도 연결될 수 있으면 true
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (connection[i][k] && connection[k][j])
                {
                    connection[i][j] = true;
                }
            }
        }
    }

    // 3 한 점으로부터 다른 점들까지 모두 연결되었는지 합을 통해서 구함.
    int conSum[N+1] = {0, };
    for (int i = 1; i <= N; i++)    
    {
        for (int j = 1; j <= N; j++)
        {
            if (connection[i][j] || connection[j][i])
            {
                conSum[i]++;
            }
        }
    }

    int count = 0;
    for(int i=1;i<=N;i++)
    {
        //cout << conSum[i] <<"\n";
        if(conSum[i] == N-1)
        {
            count ++;
        }
    }

    cout << count;

    return 0;
}