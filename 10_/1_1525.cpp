#include <iostream>
#include <queue>
#include <set>

#include <cstring>

using namespace std;

int d[4] = {-3, 3, -1, 1}; // 4방향

set<string> visitedStage; // visited
string clearStage = "123456780";

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string start;

    // 입력
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char num;
            cin >> num;
            start.push_back(num);
        }
    }

    queue<pair<string, int>> nextStage;

    // visited 이후 push
    visitedStage.insert(start);
    nextStage.push({start, 0});

    while (!nextStage.empty())
    {
        string thisStage = nextStage.front().first;
        int count = nextStage.front().second;

        nextStage.pop();

        int zeroIndex;

        // 정렬된 상태에 도달한다면, 종료
        if (thisStage == clearStage)
        {
            cout << count;
            return 0;
        }

        // 0의 인덱스를 찾음
        for (int i = 0; i < 9; i++)
        {
            if (thisStage[i] == '0')
            {
                zeroIndex = i;
            }
        }

        // 0의 위치로부터 4방향을 봄, 갈 수 있다면 간다.
        // (+visited로 같은 상태가 아니면)
        for (int i = 0; i < 4; i++)
        {
            int c = zeroIndex + d[i];
            if (c < 0 || c >= 9) // 위아래
            {
                continue;
            }
            else if (((zeroIndex + 1) % 3 == 1) && i == 2) // 왼쪽벽인데 왼쪽으로
            {
                continue;
            }
            else if (((zeroIndex + 1) % 3 == 0) && i == 3)
            {
                continue;
            }
            else
            {
                string tmpStage = thisStage;
                char tmp;
                tmp = tmpStage[c];         // 갈 수 있는 곳을 저장
                tmpStage[c] = '0';         // 갈 수 있는 곳을 실제로 감
                tmpStage[zeroIndex] = tmp; // 서로 값을 바꾸는 것
                // 그러면 지금 tmpStage는 실제로 이동한 상태

                // set의 find는 해당 원소가 없을시, end를 반환함
                if (visitedStage.find(tmpStage) == visitedStage.end())
                {
                    visitedStage.insert(tmpStage);
                    nextStage.push({tmpStage, count + 1});
                }
            }
        }
    }
    cout << -1;
    return 0;
}
