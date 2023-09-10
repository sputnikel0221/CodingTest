#include <iostream>
#include <vector>
using namespace std;

int N;
bool visited[21];
int arr[21][21];
vector<int> v;

int result=987654321;

void DFS(int num)
{
    if(v.size()==N/2)
    {
        // v속 원소의 값은 상관이 없다. visited만 체크
        int s_result=0, l_result=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1; j<=N;j++)
            {
                if(visited[i]==true&&visited[j]==true)
                {
                    s_result += arr[i][j];
                }
                if(visited[i]==false&&visited[j]==false)
                {
                    l_result += arr[i][j];
                }
            }
        }

        result = min(result, abs(s_result-l_result));
    }
    else
    {
        for(int i=num;i<=N;i++)   // num~N까지로 수정
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

    cin >> N;

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin >> arr[i][j];
        }
    }

    DFS(1); // 시작이 1이어야 함

    cout << result;

    return 0;   
}