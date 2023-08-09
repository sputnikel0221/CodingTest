#include <iostream>
#include <vector>
using namespace std;

int N, M;
int d[101][101];
int passIdx[101][101];
const int INF = 100000000;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // 1 INF
    for (int i = 1; i <= N; i++)
    {
        fill(d[i], d[i] + N + 1, INF);
    }

    // 2 입력
    while (M--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        d[a][b] = min(d[a][b], w);   // min 해줘야함
        passIdx[a][b] = b;  
    }

    // 3 본인
    for (int i = 1; i <= N; i++)
    {
        d[i][i] = 0;
    }

    // 4 Flo-War
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                // i~j로 가는 것보다 k를 거쳐서 가는 것이 빠르다면,
                if(d[i][j] >  d[i][k] + d[k][j])
                {
                    d[i][j] =  d[i][k] + d[k][j];  // d를 갱신
                    passIdx[i][j] = passIdx[i][k];   // maxIdx를 갱신 
                }
                //  따라서 i에서 j로 가는 최단경로는 i에서 k를 지나온 정점을 무조건 포함한다.
            }
        }
    }

    // 5 출력
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (d[i][j] == INF)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout << "\n";
    }

    // 5-2 출력 2
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(d[i][j] == 0 || d[i][j] == INF)  //최단경로를 표시할 수 없는 경우
            {
                cout << "0 \n";
                continue;
            }

            vector<int> path;
            int idx = i;            // i를 시작점으로 두고, j로 가는 경로를 구한다.
            while(idx != j)
            {
                path.push_back(idx);    // 지나온 정점을 역추적하여 vector에 담는다
                idx = passIdx[idx][j];
            }
            path.push_back(j);
            cout << path.size() << " ";

            for(auto x : path)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}