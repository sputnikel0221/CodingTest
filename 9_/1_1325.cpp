#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> connection[10001]; // 10000으로해도 상관없을듯
bool visited[10001] = {
    0,
};
int count[10001] = {
    0,
};

int thisIndex = 0;

void DFS(int);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M; // N은 컴퓨터의 개수, M은 신뢰 연결의 개수

    // 입력 받기
    int A, B;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;
        connection[B].push_back(A); // B를 해킹하면 A도 해킹할 수 있다
    }

    for (int i = 1; i <= 10000; i++)
    {
        memset(visited, 0, sizeof(visited));
        thisIndex = i;

        if (!connection[i].empty())
        {
            visited[i] = 1;
            DFS(i);
        }
    }

    /*
    for (int i = 1; i <= N; i++)
    {
        if (0 != count[i])
        {
            cout << i << "th computer =" << count[i] << "\n";
        }
    }
    */

    // sort
    int max = 0;
    for (int i = 1; i < 10001; i++)
    {
        if (max < count[i])
        {
            max = count[i];
        }
    }
    // cout << max;

    for (int i = 1; i < 10001; i++)
    {
        if (count[i] == max)
        {
            cout << i << " ";
        }
    }
    return 0;
}

void DFS(int num)
{
    count[thisIndex]++;
    for (int i = 0; i < connection[num].size(); i++)
    {
        if (!visited[connection[num][i]])
        {
            visited[connection[num][i]] = 1;
            DFS(connection[num][i]);
        }
    }
}