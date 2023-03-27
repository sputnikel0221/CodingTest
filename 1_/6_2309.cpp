#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int height[9] = {};
    int sum = 0;
    int bubble_tmp;

    for (int i = 0; i < 9; i++)
    {
        cin >> height[i];
    }

    // 9명 키의 전체합
    for (int num : height)
    {
        sum += num;
    }

    for (int first = 0; first < 9; first++)
    {
        for (int second = first+1; second < 9; second++)
        {
            if ((sum - (height[first] + height[second])) == 100)
            {
                //cout << "first : " << height[first] << "  second :" << height[second] << "\n\n\n\n\n" ;
                height[first] = 100;
                height[second] = 100;
                break;
            }
        }
        if(height[first] == 100){
            break;
        }
    }

    for (int a = 0; a < 9; a++)
    {
        for (int b = 0; b < 9 - a - 1; b++)
        {
            if (height[b] > height[b + 1])
            {
                bubble_tmp = height[b + 1];
                height[b + 1] = height[b];
                height[b] = bubble_tmp;
            }
        }
    }

    for (int k = 0; k < 7; k++)
    {
        cout << height[k] << "\n";
    }

    return 0;
}