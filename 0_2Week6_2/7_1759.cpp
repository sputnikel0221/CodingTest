#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<int> v;
vector<char> arr;
bool visited[16];

// 모음 자음 조건이 맞는지 체크
bool checkmoza()
{
    int mo = 0, ja = 0;
    for (int i = 0; i < N; i++)
    {
        char ch = arr[v[i]];

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            mo++;
        }
        else
        {
            ja++;
        }
    }
    if (mo >= 1 && ja >= 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DFS(int num)
{               
    if (v.size() == N)
    {
        if (checkmoza())
        {
            for (int i = 0; i < N; i++)
            {
                cout << arr[v[i]];
            }
            cout << "\n";
        }
        else
        {
            return;
        }
    }
    else
    {
        for (int i = num; i < M; i++)   // M까지인데 6으로 써놨어서..
        {
            if (!visited[i])
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        char c;
        cin >> c;
        arr.push_back(c);
    }

    sort(arr.begin(), arr.end());

    /*
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "\n";
    */

    DFS(0);

    return 0;
}