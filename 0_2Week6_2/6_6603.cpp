#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> arr;
vector<int> v;
bool visited[13] = {0, };

void DFS(int num)
{
    if(v.size()==6)
    {
        for(int i=0;i<6;i++)
        {
            cout << arr[v[i]] << " "; 
        }
        cout << "\n";
    }
    else
    {
        for(int i=num;i<N;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                v.push_back(i);
                DFS(i);
                v.pop_back();
                visited[i] = false;
            }
        } 
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        cin >> N;
        arr.clear();

        if(N==0)
        {
            break;
        }

        for(int i=0;i<N;i++)
        {
            int num;
            cin >> num;

            arr.push_back(num);
        }
        
        DFS(0);

        cout << "\n";
    }
    

    return 0;   
}