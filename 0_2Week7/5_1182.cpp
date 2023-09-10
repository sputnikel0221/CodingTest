#include <iostream>
#include <vector>
using namespace std;

int answer=0;
int N, S;
int arr[21];
bool visited[21] = {0, };
vector<int> v;

void DFS(int num)
{
    if(v.size()>=1)
    {
        int result = 0;
        for(int i=0;i<v.size();i++)
        {
            result += arr[v[i]];
        }

        if(result == S)
        {
            answer++;
        }
    }
    //else
    {
        for(int i=num;i<N;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                v.push_back(i);
                DFS(i);
                v.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> S;

    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }

    DFS(0);

    cout << answer;

    return 0;   
}