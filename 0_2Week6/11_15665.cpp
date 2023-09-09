#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
int visited[9] = {0, }; // visited도 int로 선언, 중복이 있을 수 있기 때문

int num_count[10001] = {0,};    // 숫자가 몇 개 입력으로 주어졌는지 확인
vector<int> v;

void DFS(int n, int num)
{
    if(n==M)
    {
        for(int i=0;i<M;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for(int i=num;i<v.size();i++)
        {
            if(visited[i] < M)    // 핵심코드
            {
                visited[i]++;
                arr[n] = v[i];
                DFS(n+1, i);
                visited[i]--;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;


    for(int i=0;i<N;i++)
    {
        int num;
        cin >> num;

        if(!num_count[num])
        {
            v.push_back(num);
        }

        num_count[num]++;
    }
    sort(v.begin(), v.end());

    DFS(0,0);

    return 0;   
}