#include <iostream>
using namespace std;

int N, M;   
int arr[9];         // 답을 저장하는 배열
bool visited[9];    // DFS 방문확인 배열

void DFS(int n)
{
    if(n==M)    // M 개수를 채웠다면, 출력 후 종료
    {
        for(int i=0;i<M;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else    // M 개수를 채우지 못했다면, DFS를 타고 들어감.
    {
        for(int i=1;i<=N;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                arr[n] = i;
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

    DFS(0);

    return 0;   
}