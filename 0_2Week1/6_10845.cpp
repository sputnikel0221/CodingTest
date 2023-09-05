#include <iostream>
using namespace std;

int front = 0, back = 0;
int q[10001] = {
    0,
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--)
    {
        string com;
        cin >> com;

        if (com == "push")
        {
            int n;
            cin >> n;

            q[back] = n;
            back++;
        }
        else if (com == "pop")
        {
            if (back - front == 0)
            {
                cout << -1 << "\n";
                continue;
            }
            cout << q[front] << "\n";
            front++;
        }
        else if (com == "size")
        {
            cout << back - front << "\n";
        }
        else if (com == "empty")
        {
            if (back - front == 0)
            {
                cout << 1 << "\n";
                continue;
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (com == "front")
        {
            if (back - front == 0)
            {
                cout << -1 << "\n";
                continue;
            }

            cout << q[front] << "\n";
        }
        else if (com == "back")
        {
            if (back - front == 0)
            {
                cout << -1 << "\n";
                continue;
            }

            cout << q[back - 1] << "\n";
        }
    }

    return 0;
}