#include <iostream>
using namespace std;

int N, M;
int arr[8];
int visited[8]; // int형으로 구현하여 중복방문 가능

void DFS(int n)
{
    if (n == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] < M)
            {
                visited[i]++;
                arr[n] = i;
                DFS(n+1);
                visited[i]--;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    DFS(0);

    return 0;
}