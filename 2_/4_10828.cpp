#include <iostream>
using namespace std;

int stack[100000]; // 임의의 stack
int stack_size = 0;

void s_push(int value);
void s_pop();
void s_size();
void s_empty();
void s_top();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 명령어 모드
    string mode;
    int input_value;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> mode;

        if (mode == "push")
        {
            cin >> input_value;;
            s_push(input_value);
        }
        else if (mode == "pop")
        {
            s_pop();
        }
        else if (mode == "size")
        {
            s_size();
        }
        else if (mode == "empty")
        {
            s_empty();
        }
        else if (mode == "top")
        {
            s_top();
        }
    }
    return 0;
}

// size가 가리키는 위치에 넣고, size++
void s_push(int value)
{
    stack[stack_size] = value;
    stack_size++;
}
void s_pop()
{
    if (stack_size >= 1)
    {
        cout << stack[stack_size - 1] << '\n';
        stack[stack_size - 1] = 0;
        stack_size--;
    }
    else
    {
        cout << -1 << '\n';
    }
}
void s_size()
{
    cout << stack_size << '\n';
}
void s_empty()
{
    if (stack_size == 0)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}
void s_top()
{
    if (stack_size == 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << stack[stack_size - 1] << '\n';
    }
}

