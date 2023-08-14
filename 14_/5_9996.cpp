#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<char> front;
    vector<char> back;

    string str;
    cin >> str;

    // 입력값을 2개의 vector에 나눠서 저장
    bool isBack = false;
    for(char c:str)
    {
        if(!isBack)
        {
            if(c == '*')
            {
                isBack = true;
                continue;
            }
            front.push_back(c);
        }
        else
        {
            back.push_back(c);
        }
    }

    while(N--)
    {
        string s;
        cin >> s;
        bool badWord = false; // 플래그

        // 중요한 조건
        if(s.size() < front.size()+back.size())
        {
            cout << "NE\n";
            continue;
        }

        //앞 확인
        for(int i=0;i<front.size();i++)
        {
            if(s[i] != front[i])
            {
                badWord = true;
            }
        }
        //뒤 확인
        for(int i=0;i<back.size();i++)
        {
            if(s[s.size()-1-i] != back[back.size()-1-i])
            {
                badWord = true;
            }
        }

        //출력
        if(badWord)
        {
            cout << "NE\n";
        }
        else
        {
            cout << "DA\n";
        }
    }

    return 0;   
}