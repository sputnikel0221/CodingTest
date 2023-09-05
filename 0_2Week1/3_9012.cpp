#include <iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    
    while(T--)
    {
        stack<char> st;

        string s;
        cin >> s;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                st.push('(');
            }
            else
            {
                if(!st.empty())
                {
                    st.pop();
                }
                else
                {
                    st.push('(');
                    break;
                }
            }
        }

        if(!st.empty())
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }

    }

    return 0;   
}