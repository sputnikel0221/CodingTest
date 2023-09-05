#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    queue<int> q;
    queue<int> result;

    for (int i = 1; i < N + 1; i++)
    {
        q.push(i);
    }

    int tmpK=0;
    while (!q.empty())
    {
        tmpK++;
        if(tmpK==K)
        {
            int tmp = q.front();
            result.push(tmp);
            q.pop();
            tmpK=0;
        }
        else
        {
            int tmp = q.front();
            q.push(tmp);
            q.pop();
        }
    }

    cout << '<';
    while(!result.empty())
    {
        if(result.size()==1)
        {
            cout << result.front();
            cout << '>';
            return 0;
        }
        cout << result.front() << ", ";
        result.pop();
    }
    

    return 0;
}