#include <iostream>

using namespace std;

int N;
void DFS(int, int);
bool map[26][26];

int dx[4] = {0,-1,0,1}; //위왼아오
int dy[4] = {1,0,-1,0};

int count = 0;
int sum[320] = {0, }; //0 인덱스는 무시

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    //입력
    string s;
    for(int i=0;i<N;i++)
    {
        cin >> s;
        for(int j=0;j<N;j++)
        {
            map[i][j] = s[j] -'0';
        }
    }

    //DFS
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j] == 1)
            {
                //cout << "map==1 yx : [" << j << "]" << "[" << i << "]" << "\n";
                DFS(i,j);
                count++;
            } 
        }
    }

    //버블정렬
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<count-i-1;j++)
        {
            if(sum[j] > sum[j+1])
            {
                int tmp = sum[j+1];
                sum[j+1] = sum[j];
                sum[j] = tmp;
            }
        }
    }

    cout << count;
    for(int i=0;i<count;i++)
    {
        cout << "\n" << sum[i];
    }
    return 0;   

}

void DFS(int x, int y)
{
    if(map[x][y] == 0)
    {
        return;
    }
    else
    {
        sum[count]++;
        map[x][y] = 0;
    }

    for(int i=0;i<4;i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(cx < 0 || N < cx || cy < 0 || N < cy)
        {
            continue;
        }
        else
        {
            DFS(cx, cy);
        }
    }
}