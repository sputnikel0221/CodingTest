#include <iostream>
#include <stack>

using namespace std;

stack<char> c_left;
stack<char> c_right;

void P(int ch)
{
    c_left.push(ch);
}
void L()
{
    if (!c_left.empty())
    {
        c_right.push(c_left.top());
        c_left.pop();
    }
}
void D()
{
    if (!c_right.empty())
    {
        c_left.push(c_right.top());
        c_right.pop();
    }
}
void B()
{
    if (!c_left.empty())
    {
        c_left.pop();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        c_left.push(s[i]);
    }

    int T;
    cin >> T;

    while (T--)
    {
        char command;
        cin >> command;

        if (command == 'P')
        {
            char ch;
            cin >> ch;
            P(ch);
        }
        else if (command == 'L')
        {
            L();
        }
        else if (command == 'D')
        {
            D();
        }
        else if (command == 'B')
        {
            B();
        }
    }

    while (!c_left.empty())
    {
        c_right.push(c_left.top());
        c_left.pop();
    }

    while (!c_right.empty())
    {
        cout << c_right.top();
        c_right.pop();
    }

    return 0;
}