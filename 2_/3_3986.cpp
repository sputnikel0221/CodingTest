#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int count = 0;

    string this_stirng;
    char input_char;

    cin >> N;

    // case 만큼 반복,
    for (int i = 0; i < N; i++)
    {
        stack<char> input_stack;
        cin >> this_stirng;

        // 해당 string의 글자수만큼 반복,
        for (int k = 0; k < this_stirng.length(); k++)
        {
            if (input_stack.size() == 0)
            {
                input_stack.push(this_stirng[k]);
            }
            else
            {
                if (input_stack.top() == this_stirng[k])
                {
                    input_stack.pop();
                }
                else
                {
                    input_stack.push(this_stirng[k]);
                }
            }
        }

        if (input_stack.size() == 0)
        {
            count++;
        }
    }

    cout << count;

    return 0;
}