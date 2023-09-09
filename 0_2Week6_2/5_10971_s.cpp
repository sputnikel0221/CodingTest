#include <iostream>
#include <vector>
using namespace std;

int N;
int w[10][10];
bool visited[10];
vector<int> v;
int result = 100000000;

void DFS()
{
    if(v.size() == N)
    {
        //v.push_back(v[0]);  // 순회해야 하므로 처음 값 추가

        int tmp = 0;
        
        cout << v[0] << " : ";
        for(int i=0;i<N-1;i++)
        {
            cout << v[i+1] << " : ";
            if(w[v[i]][v[i+1]] != 0)    // 경로가 있다면,
            {
                tmp += w[v[i]][v[i+1]];
            }
            else
            {
                return; // 경로가 없다면, result를 갱신하지 않고 바로 return
            }            
        }
        
        // 순회해야 하므로 
        if(w[N-1][v[0]]!=0)
        {
            tmp+=w[v[N-1]][v[0]];
        }
        else
        {
            return;
        }

        cout << "= " << tmp << " \n ";
        result = min(result, tmp);
        return;
    }
    else
    {
        for(int i=0;i<N;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                v.push_back(i);
                DFS();
                v.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> w[i][j];
        }
    }

    DFS();

    cout << result;

    return 0;   
}