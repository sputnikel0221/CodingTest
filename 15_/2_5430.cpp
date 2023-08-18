#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        string command;
        cin >> command;

        int n;      //해당 값이 0이면 문제가 생김
        cin >> n;

        string arr;
        cin >> arr;

        bool isReversed = false; // reverse를 수행할 것
        bool isError = false;

        // 1 Data Parsing
        int startIdx = 0;
        int endIdx = n-1;
        int Idx = 0;
        int realArray[n];


        string tmpString = "";
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == '[')
            {
                continue;
            }
            
            if (arr[i] == ']')
            {
                if (tmpString != "")
                {
                    int num = stoi(tmpString);
                    // cout << "input : " << num << "\n";
                    realArray[Idx] = num;
                }
                continue;
            }

            if (arr[i] == ',')
            {
                int num = stoi(tmpString);
                // cout << "input : " << num << "\n";
                realArray[Idx] = num;
                Idx++;
                tmpString = "";
                continue;
            }
            tmpString += arr[i];
        }

        // 인덱스 수정으로 삭제효과
        startIdx = 0;
        endIdx = n-1;

        // command line에 맞게 수정
        for (int i = 0; i < command.size(); i++)
        {
            if (command[i] == 'R')
            {
                if (isReversed)
                {
                    isReversed = false;
                }
                else
                {
                    isReversed = true;
                }
            }
            
            if (command[i] == 'D')
            {
                if (startIdx > endIdx || endIdx == -1)
                {
                    cout << "error\n";
                    isError = true;
                    break;
                }

                if (isReversed) //1 reverse 된 상황에서 맨 앞의 것을 뺀다면,
                {
                    endIdx --;  // 그냥 뒤 인덱스를 하나 줄인다.
                }
                else            //2 그냥 상태에서 맨 앞의 것을 뺀다면,
                {
                    startIdx ++; // 그냥 앞 인덱스를 하나 늘린다.
                }
            }
        }

        // Error라면 출력을 건너뜀
        if (isError)
        {
            continue;
        }

        // 출력 - reverse라면, index를 거꾸로 출력
        cout << "[";
        if (isReversed)
        {
            for (int i = endIdx; i >= startIdx; i--)
            {
                cout << realArray[i];
                if (i == startIdx)
                {
                    cout << "]\n";
                    break;
                }
                cout << ",";
            }
        }
        else
        {
            for (int i = startIdx; i <= endIdx; i++)
            {
                cout << realArray[i];
                if (i == endIdx)
                {
                    cout << "]\n";
                    break;
                }
                cout << ",";
            }
        }

        // 문자가 0개인 경우, ]를 표시할 수 없으므로 이렇게 예외처리
        if(startIdx > endIdx)
        {
            cout << "]\n";
        }
    }
    

    return 0;
}