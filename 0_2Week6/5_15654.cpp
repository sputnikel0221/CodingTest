#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N, M;
vector<int> v;
int arr[9];
bool visited[9] = {0, };

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
            if (!visited[i])
            {
                visited[i] = true;
                arr[n] = v[i];  // 문제된 부분
                DFS(n+1);
                visited[i] = false;
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

        v.push_back(num);
    }
    sort(v.begin(), v.end());

    DFS(0);

    return 0;   
}