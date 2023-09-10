#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
char sim[12] = {0, };
bool visited[12];
vector<char> v;

string max_num="0", min_num="90000000000";
void DFS(int n, int num)
{
    if(v.size()==N+1)
    {
        string s;
        for(int i=0;i<v.size();i++)
        {
            s+=v[i];
        }

        //cout << "String is : " << s << "\n";
        if(stoll(max_num) < stoll(s))
        {
            max_num = s;
        }

        if(stoll(min_num) > stoll(s))
        {
            min_num = s;
        }
    }
    else
    {
        if(sim[n]=='<')
        {
            for(int i=num;i<10;i++)
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    v.push_back(i + '0');
                    DFS(n+1, i);
                    v.pop_back();
                    visited[i] = false;
                }
            }
        }
        else if(sim[n]=='>')
        {
            for(int i=num;i>=0;i--)
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    v.push_back(i + '0');
                    DFS(n+1, i);
                    v.pop_back();
                    visited[i] = false;
                }
            }
        }
        else    // 시작
        {
            for(int i=num;i<10;i++)
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    v.push_back(i + '0');
                    DFS(n+1, i);
                    v.pop_back();
                    visited[i] = false;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=1;i<=N;i++)
    {
        cin >> sim[i];
    }

    DFS(0,0);

    cout << max_num << "\n" << min_num;

    return 0;   
}