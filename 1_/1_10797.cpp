#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    int count = 0;
    int car_num;

    cin >> num;

    for (int i = 0; i < 5; i++)
    {
        cin >> car_num;
        if(car_num == num){
            count++;
        }
    }

    cout << count;
    
    return 0;   
}
