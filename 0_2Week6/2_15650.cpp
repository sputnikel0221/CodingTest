#include <iostream>
using namespace std;

int N, M;   
int arr[9];         // 답을 저장하는 배열
bool visited[9];    // DFS 방문확인 배열

void DFS(int n, int num)    // 1 num을 추가함으로써
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
        for(int i=num;i<=N;i++) // 2 num 다음의 값들만 다루도록 함
        {
            if(!visited[i])
            {
                visited[i] = true;
                arr[n] = i;
                DFS(n+1, i);
                visited[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N >> M;

    DFS(0, 1);  // 현재 개수는 0이고, 1이 들어가면 식이 시작이 됨.

    return 0;   
}