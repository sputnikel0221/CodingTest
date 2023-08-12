#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    // cout << 'a' << " : " << "a" - 97;
    // cout << 'z' << " : " << 'z' - 97;
    
    int count = 0;
    while(N--)
    {
        bool cantGroup = false;
        bool visited[26] = {0, };
        string s;
        cin >> s;

        for(int i=0; i<s.size(); i++)
        {
            if(i == 0)
            {
                visited[s[i] - 97] = true;
            }
            else
            {
                if(s[i-1] != s[i])
                {
                    if(visited[s[i] - 97] == true)
                    {
                        cantGroup = true;
                    }
                    else
                    {
                        visited[s[i] - 97] = true;
                    }
                }
            }
        }

        if(cantGroup)
        {
            continue;
        }
        count ++;
    }

    
    cout << count;

    return 0;   
}