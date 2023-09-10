#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    bool arr[N+1][N+1];
    for(int i=0;i<M;i++)
    {
        int from, to;
        cin >> from >> to;

        arr[from][to] = true;
        arr[to][from] = true;
    }

    queue<int> q;
    q.push(0);

    

    return 0;   
}