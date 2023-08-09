#include <iostream>
#include <limits>

using namespace std;

//const int INF = numeric_limits<int>::max();
const int INF = 100000000;
int d[101][101];
int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // INF로 다 채워둠
    for (int i = 1; i <= N; i++)
    {
        fill(d[i], d[i] + N + 1, INF);
    }

    // 연결 입력을 받아서 d에 바로 저장
    while (M--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        d[a][b] = min(d[a][b], w); // 시작/도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
    }


    // 본인과의 거리는 0으로 설정
    for (int i = 1; i <= N; i++)
    {
        d[i][i] = 0;
    }


    // Flo-War
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); // 단순 연산 및 대입
            }
        }
    }

    // 출력
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (d[i][j] == INF)
            {
                cout << "0 ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}