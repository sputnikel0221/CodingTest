#include <iostream>
using namespace std;

int main()
{
    // ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int one_roll;
    int dice_Result[7] = {};
    int count;

    // 예외상황들에 대한 변수
    bool two_two = false;
    int one_one_one_one = 0;
    int max = 0;

    cin >> N;
    int tmp_get = 0;
    int max_get = 0;

    // N명의 사람들마다
    for (int i = 0; i < N; i++)
    {
        // 4개의 주사위를 던진다.
        for (int roll = 0; roll < 4; roll++)
        {
            // scanf("%d", &one_roll);
            cin >> one_roll;
            dice_Result[one_roll]++;
            // cout << "roll : " << roll << "num :" << one_roll << "\n";
        }
        // 1~6의 숫자가 몇개씩 나왔는지 판단하여, 상금을 부여한다.
        for (int num = 1; num <= 6; num++)
        {
            if (dice_Result[num] >= 1)
            {
                if (dice_Result[num] >= 2)
                {
                    if (dice_Result[num] >= 3)
                    {
                        if (dice_Result[num] == 4)
                        {
                            tmp_get += 50000 + num * 5000;
                            //cout << "4개짜리 \n";
                        }
                        else
                        {
                            tmp_get += 10000 + num * 1000;
                            //cout << "3개짜리 \n";
                        }
                    }
                    else
                    {
                        if (two_two == true)
                        {
                            int x = (tmp_get - 1000) / 100; //x를 유추
                            tmp_get = 0;
                            tmp_get += 2000 + num * 500 + x * 500;
                        }
                        else
                        {
                            tmp_get += 1000 + num * 100;
                            two_two = true;
                        }
                    }
                }
                else
                {
                    one_one_one_one++;

                    if (max < num)
                    {
                        max = num;
                    }
                    if (one_one_one_one == 4)
                    {
                        //cout << "1개짜리 싹다\n";
                        tmp_get = max * 100;
                    }
                }
            }
            if (max_get < tmp_get)
            {
                max_get = tmp_get;
            }
        }
        //cout << i << " : " << tmp_get << "\n";

        // 변수 초기화
        fill_n(dice_Result, 7, 0);
        tmp_get = 0;

        two_two = false;
        one_one_one_one = 0;
        max = 0;
    }

    cout << max_get;

    return 0;
}