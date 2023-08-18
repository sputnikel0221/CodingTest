#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    cin >> T;

    // T = TestCase
    while (T--)
    {
        bool NoFlag = false;
        cin >> N;
        vector<string> Number;

        // 1 전화번호 입력을 받아서 벡터에 저장
        for (int i = 0; i < N; i++)
        {
            string sinput;
            cin >> sinput;
            Number.push_back(sinput);
        }

        // 2 Sort를 진행 - 가장 중요한 부분
        sort(Number.begin(), Number.end());

        // 3 본인과 본인 다음의 것만 비교
        for (int i = 0; i < Number.size() - 1; i++)
		{
			if (Number[i] == Number[i + 1].substr(0, Number[i].size()))
            {
                cout << "NO\n";
                NoFlag = true;
                break;
            }				
		}

        // 4 NoFlag로 출력 구분
        if(NoFlag)
        {
            continue;
        }

        cout << "YES\n";      
    }

    return 0;
}