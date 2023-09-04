#include <iostream>
using namespace std;


int Stack[10001] = {0, };
int topIdx = 0;

void push(int n)
{
    Stack[topIdx] = n;
    topIdx++;
}

void pop()
{
    //cout << "pop\n";
    if(topIdx==0)
    {
        cout << -1 << "\n";
        return;
    }
    cout << Stack[topIdx-1] << "\n";
    topIdx--;
}

void size()
{
    //cout << "size\n";
    cout << topIdx << "\n";
}

void empty()
{
    //cout << "empty\n";
    if(topIdx == 0)
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}

void top()
{
    //cout << "top\n";
    //cout << "top idx : " << topIdx << "\n";
    if(topIdx==0)
    {
        cout << -1 << "\n";
        return;
    }
    cout << Stack[topIdx-1] << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while(N--)
    {
        string s;
        cin >> s;

        if(s=="push")
        {
            int n;
            cin >> n;
            push(n);
        }
        else if(s=="pop")
        {
            pop();
        }
        else if(s=="size")
        {
            size();
        }
        else if(s=="empty")
        {
            empty();
        }
        else if(s=="top")
        {
            top();
        }
    }

    return 0;   
}