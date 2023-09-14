#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
queue<pair<pair<int, int>,int>> q;

// 왠만해선 vector로 map 구현할 것 (시간초과)
vector<int> map[1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int result = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    // 입력
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int n;
            cin >> n;
            map[i].push_back(n);
        }
    }

    // 1 queue에 시작점들 넣음
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(map[i][j]==1)
            {
                q.push({{i,j},0});
            }
        }
    }

    // 2 BFS - 각 시작점으로부터 동시에 퍼짐
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int day = q.front().second;

        q.pop();

        result = max(result, day);

         for(int i=0;i<4;i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];

            if(cx < 0 || cx >= N || cy < 0 || cy >= M)
            {
                continue;
            }

            if(map[cx][cy]==0)
            {
                map[cx][cy] = 1;
                q.push({{cx,cy}, day+1});
            }
        }
    }

    // 3 출력 - 결과에 0이 있으면 -1 출력
    for(int i=0;i<N;i++)
    {
        for(auto j : map[i])
        {
            if(j==0)
            {
                cout << -1;
                return 0;
            }
        }
    }

    // 4 출력 - 문제 없을 경우
    cout << result;

    return 0;   
}