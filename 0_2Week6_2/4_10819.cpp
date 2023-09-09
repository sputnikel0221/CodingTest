#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int result = 0;
vector<int> v;
int arr[9];
bool visited[9] = {
    0,
};

void DFS() // int n을 받지 않을거면 vector를 사용하면 편리
{
    // 모든 원소를 다 채웠으면, 합을 확인, 최대면 갱신
    if (v.size() == N)
    {
        int tmp = 0;
        for (int i = 0; i < N - 1; i++)
        {
            tmp += abs(v[i + 1] - v[i]);
        }
        result = max(result, tmp);
        return;
    }
    else
    {
        for (int i = 0; i < N; i++)
        { 
            if (!visited[i])
            {
                visited[i] = true;
                v.push_back(arr[i]);
                DFS();
                v.pop_back();       // vector를 사용한 dfs는 이렇게 한다.
                visited[i] = false;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    DFS();

    cout << result; //result를 여기에 적어야만 한다.

    return 0;
}