#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[9];
int visited[9] = {0, };

int num_count[10001] = {0,};
vector<int> v;

void DFS(int n)
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
        for(int i=0;i<N;i++)
        {
            if(visited[i] < num_count[v[i]])
            {
                visited[i]++;
                arr[n] = v[i];
                DFS(n+1);
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

    DFS(0);

    return 0;   
}