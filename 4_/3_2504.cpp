#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int sum=0;
    int tmpSum[s.length()] = {0, }; //계층은 최대 length/2개
    int rank=0; //계층
    // [ 1식[ 2식[ 3식[ 4식 ]]]]

    // 연산 플래그를 적용한다
    // 0- 아무것도 아님 / 1- ( 일단 덧셈, 곱 미정 / 2- [ 일단 덧셈, 곱 미정
    // 3- 2배곱 확정 / 4- 3배곱 확정
    int exprArray[s.length()] = {0, };
    int sIndex=0;    //스택의 pop연산 이후 인덱스 // 추가되는 값은 i에 넣어야 함
                    //i에는 의미없는 값이 있을 수 있다. 현재i만 의미가 있다.
                    //현재 들어갈 수 있는 곳이 sIndex의 위치;
    //*  ( ( ) [ [ ] ] ) ( [ ] )     ( ) [ ] [ ]  ( [ ( ) ] )
    for(int i=0; i<s.length(); i++)
    {
        char c = s[i];

        //sIndex는 Stack을 나타낼 인덱스로, 열기괄호면 추가, 닫기괄호면 감소
        //*1- 여는괄호가 들어온 경우
        if(c == '(' || c == '[')
        {
            if(sIndex!=0)
            {
                // 앞의 괄호가 덧셈지정만 되어있다면 곱셈으로 승격시킨다.
                if(exprArray[sIndex-1]==1 || exprArray[sIndex-1]==2)
                {
                    exprArray[sIndex-1]==1? exprArray[sIndex-1]=3 : exprArray[sIndex-1]=4;
                    rank++; // 여는괄호다음 여는괄호여야 rank를 추가
                }
                // 현재 괄호가 ( 면 1, [ 면 2로 둔다
                c=='(' ? exprArray[sIndex]=1 : exprArray[sIndex]=2;

                sIndex++;
            } 
            else //(sIndex==0)
            {
                // 현재 괄호 값만 설정
                c=='(' ? exprArray[sIndex]=1 : exprArray[sIndex]=2;
                
                sIndex++;
            }
        }
        //*2- 닫는괄호가 들어온 경우 - 여는괄호를 제거
        else if(c == ')' || c == ']')
        {
            // 1 닫는괄호가 왔는데 아무것도 없으면 오류
            if(sIndex==0)
            {
                sIndex++; //일부러 증가시키고 종료
                break;
            }
            // 2 여는괄호 목록이 존재한다면,
            else
            {
                // 본인이 ) 일때,
                if( c==')' )
                {
                    // 1- 여는괄호가 단지 1이면, tmpSum에 덧셈연산
                    if(exprArray[sIndex-1]==1)
                    {
                        tmpSum[rank] += 2;
                    }
                    // 2- 여는괄호가 3이면, 여태의 tmpSum에 곱셈연산/덧셈 및 초기화
                    else if(exprArray[sIndex-1]==3)
                    {
                        tmpSum[rank] *= 2;
                        if(!(rank-1<0))
                        {
                            tmpSum[rank-1] += tmpSum[rank];
                            tmpSum[rank] = 0;
                        }
                        rank--;
                    }
                    else
                    {
                        break;
                    }
                }
                // 본인이 ] 일때,
                else
                {
                    if(exprArray[sIndex-1]==2) 
                    {
                        tmpSum[rank] += 3;
                    }
                    else if(exprArray[sIndex-1]==4)
                    {
                        tmpSum[rank] *= 3;
                        if((rank-1) >= 0)
                        {
                            tmpSum[rank-1] += tmpSum[rank];
                            tmpSum[rank] = 0;
                        }
                        rank--;
                    }
                    else
                    {
                        break;
                    }
                }
                sIndex--;
                if(sIndex==0)
                {
                    tmpSum[0] += tmpSum[1];
                    tmpSum[1] = 0;
                }            
            }
        }
    }

    // 최종 sum 출력
    // stack이 비지 않았다면 오류
    if(sIndex!=0)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << tmpSum[0] << "\n";
    }
    
    return 0;   
}