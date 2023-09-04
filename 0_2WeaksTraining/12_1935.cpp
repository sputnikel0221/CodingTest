#include <iostream>
#include <stack>
#include <iomanip>

using namespace std;

int value[26] = {
    0,
};

int main()
{
    ios::sync_with_stdio(0); // 이걸 지우면 printf scanf를 사용할 수 있다.
    cin.tie(0);

    int N;
    cin >> N;
    cin.ignore();

    string s;
    getline(cin, s);

    for (int i = 0; i < N; i++)
    {
        cin >> value[i];
    }

    stack<double> st;
    float ans;

    for (int i = 0; i < s.length(); i++)
    {
        // alpha
        if (65 <= s[i] - 0 && s[i] - 0 <= 92)
        {
            st.push(value[s[i] - 65]);
        }
        else
        {
            double b = st.top();
            st.pop();
            double a = st.top();
            st.pop();

            if (s[i] == '+')
            {
                //cout << "+ : "<< a+b << "\n";
                st.push(a + b);
            }
            else if (s[i] == '-')
            {
                //cout << "- : "<< a-b << "\n";
                st.push(a-b);
            }
            else if (s[i] == '*')
            {
                //cout << "* : "<< a << "*" << b <<" = "<< a*b << "\n";
                st.push(a*b);
            }
            else if (s[i] == '/')
            {
                //cout << "/ : "<< a << "/" << b <<" = "<< "\n";
                st.push(a/b);
            }
        }
    }
    cout << fixed << setprecision(2) << st.top();
    //cout << st.top() + 0.00f;

    return 0;
}