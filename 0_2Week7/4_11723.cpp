#include <iostream>
using namespace std;

int idx = 0;
bool S[21]={0,};

void add(int n)
{
    if(!S[n])
    {
        S[n] = true;
    }
}

void remove(int n)
{
    if(S[n])
    {
        S[n] = false;
    }
}

void check(int n)
{
    if(S[n])
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
}

void toggle(int n)
{
    if(S[n])
    {
        S[n] = false;
    }
    else
    {
        S[n] = true;
    }
}

void all()
{
    for(int i=1;i<=20;i++)
    {
        S[i] = true;
    }
}

void empty()
{
    for(int i=1;i<=20;i++)
    {
        S[i] = false;
    }
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

        if (s == "add")
        {
            int n;
            cin >> n;

            add(n);
        }
        else if (s == "remove")
        {
            int n;
            cin >> n;

            remove(n);
        }
        else if (s == "check")
        {
            int n;
            cin >> n;

            check(n);
        }
        else if (s == "toggle")
        {
            int n;
            cin >> n;

            toggle(n);
        }
        else if (s == "all")
        {
            all();
        }
        else if (s == "empty")
        {
            empty();
        }
    }

    return 0;
}