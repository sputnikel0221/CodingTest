#include <iostream>
using namespace std;

int N, M;
int arr[9];
int visited[9]; // int형으로 구현하여 중복방문 가능

void DFS(int n, int num)
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
        for (int i = num; i <= N; i++)
        {
            if (visited[i] < M)
            {
                visited[i]++;
                arr[n] = i;
                DFS(n+1, i);
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

    DFS(0, 1);

    return 0;
}