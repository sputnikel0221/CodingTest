#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    cin.ignore(); // 중요
    //getline(cin, s);

    string s;
    stack<char> st;

    while(T--)
    {
        getline(cin, s);
        s+= " ";

        for(int i=0; i<s.length();i++)
        {
            if(s[i] == ' ')
            {
                while(!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
            else
            {
                st.push(s[i]);
            }
        }

        cout << "\n";
    }
    return 0;   
}