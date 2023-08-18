#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    string bomb;

    cin >> str >> bomb;

    int slen = str.length();
    int blen = bomb.length();

    stack<char> answer;
    stack<char> chkBomb; 
    int idx = 0;

    for(int i=0;i<slen;i++)
    {
        answer.push(str[i]);

        // 현재 글자가 bomb의 마지막 글자와 같다면,
        if(str[i]==bomb[blen-1] && answer.size()>=blen)
        {
            // 뒷글자부터 앞까지 blen만큼 비교한다.
            for(int k=blen-1;k>=0;k--)
            {
                // 맨뒤와 bomb의 뒤가 같으면 pop연산을 한다. 
                // 아닐 경우를 대비해서 queue에 push한다.
                if(bomb[k]==answer.top())
                {
                    chkBomb.push(answer.top());
                    answer.pop();

                    // 끝까지 갔다면 기억하고 있을 필요가 없으므로 삭제
                    if(k==0)
                    {
                        while(!chkBomb.empty())
                        {
                            chkBomb.pop();
                        }
                    }
                }
                // 아닐경우, 모든 값을 다시 push한다.
                else
                {
                    while(!chkBomb.empty())
                    {
                        answer.push(chkBomb.top());  
                        chkBomb.pop();
                    }
                }
            }
        }
    }

    int aSize = answer.size();

    // 예외처리
    if(aSize == 0)
    {
        cout << "FRULA";
        return 0;
    }

    // 출력을 위해서 stack을 뒤집는다
    stack<char> reverseStack;
    while (aSize--)
    {
        reverseStack.push(answer.top());
        answer.pop();
    }

    // 진짜 출력
    int rSize = reverseStack.size();
    while (rSize--)
    {
        cout << reverseStack.top();
        reverseStack.pop();
    }

    return 0;   
}