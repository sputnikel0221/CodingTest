#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int N, M;
int sum=0;
//string map[100];
vector<string> map;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i=0; i<N; i++)
    {   
        string s;
        cin >> s;
        map.push_back(s);
    }    

    queue<pair<pair<int, int>,int>> q;
    q.push({{0,0},1});

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int count = q.front().second;
        map[x][y] = '0';
        q.pop();

        if(x==N-1 && y==M-1)
        {
            cout << count;
            return 0;
        }

        for(int i=0;i<4;i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];

            if(cx < 0 || cx >= N || cy < 0 || cy >= M)
            {
                continue;
            }

            if(map[cx][cy]=='1')
            {
                map[cx][cy] = '0';  // BFS 큐에 들어가기 전에 방문표시를 해야 함
                q.push({{cx, cy},count+1});
            }
        }

    }

    return 0;   
}