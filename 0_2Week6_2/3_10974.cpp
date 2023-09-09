#include <iostream>
using namespace std;

int N;

int arr[9];
bool visited[9];

void DFS(int n)
{
    if(n==N)
    {
        for(int i=0;i<N;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else
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

    cin >> N;

    DFS(0);

    return 0;   
}