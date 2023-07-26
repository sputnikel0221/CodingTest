#include <iostream>
using namespace std;


void deleteMax();
void add(int num);

int maxIndex=0;     //max값을 가지고 있는 인덱스
int sizeArr = 0;    //Array의 유의미한 부분의 size를 정의함
int array[100000] = {0, }; //100000개 선언해둠

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int num;
    for(int i=0; i<N; i++)
    {
        cin >> num;
        if(num==0)
        {
            deleteMax();
        }
        else
        {
            add(num);
        }
    }

    return 0;   
}

// 최대값을 출력하고, 해당 원소 삭제
void deleteMax()
{
    if(sizeArr==0)
    {
        cout << 0 << "\n";  //이번 문제에서 가장 중요했던 부분, endl로 쓰니 시간초과가....
    }
    else
    {
        // 1. 최대값을 찾기 위한 로직
        int maxNum = 0;
        for(int i=0; i<=sizeArr;i++)    //++size이라 <=sizeArr
        {                               //단순히 sizeArr만큼 원소가 들어왔을 것이고, 
                                        //그이후가 0으로 삭제되더라도 100000개보단 범위를 줄일 수 있게 된다.
            // 2. 더 큰값을 찾았다면, 계속 갱신
            if(maxNum < array[i])
            {
                maxNum = array[i];
                maxIndex = i;
            }
        }
        // 3. 최대값 출력 및 해당 값의 원소를 0으로 바꿈
        cout << maxNum << "\n"; 
        array[maxIndex] = 0; //삭제 대신 0으로 수정
    }
    
}

// size는 여기에서 추가된다. 0말고 1부터진행(sizeArr++로 써도 상관없겠다)
void add(int num)
{
    array[++sizeArr] = num;
}
