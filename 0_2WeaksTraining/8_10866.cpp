#include <iostream>
using namespace std;

int ifront = 15000, iback = 15000;
int deque[30001] = {
    0,
};

void push_front(int x)
{
    ifront--;
    deque[ifront] = x;
}
void push_back(int x)
{
    deque[iback] = x;
    iback++;
}
void pop_front()
{
    if (iback - ifront == 0)
    {
        cout << -1 << "\n";
        return;
    }
    cout << deque[ifront] << "\n";
    ifront++;
}
void pop_back()
{
    if (iback - ifront == 0)
    {
        cout << -1 << "\n";
        return;
    }
    iback--;
    cout << deque[iback] << "\n";
}
void size()
{
    cout << iback - ifront << "\n";
}
void empty()
{
    if (iback - ifront == 0)
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}
void front()
{
    if (iback - ifront == 0)
    {
        cout << -1 << "\n";
        return;
    }

    cout << deque[ifront] << "\n";
}
void back()
{
    if (iback - ifront == 0)
    {
        cout << -1 << "\n";
        return;
    }

    cout << deque[iback-1] << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;

        if (s == "push_front")
        {
            int n;
            cin >> n;

            push_front(n);
        }
        else if (s == "push_back")
        {
            int n;
            cin >> n;

            push_back(n);
        }
        else if (s == "pop_front")
        {
            pop_front();
        }
        else if (s == "pop_back")
        {
            pop_back();
        }
        else if (s == "size")
        {
            size();
        }
        else if (s == "empty")
        {
            empty();
        }
        else if (s == "front")
        {
            front();
        }
        else if (s == "back")
        {
            back();
        }
    }

    return 0;
}