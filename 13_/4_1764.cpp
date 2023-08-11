#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;   // 듣지도 못한사람 목록

    int N, M;
    cin >> N >> M;

    set<string> d;

    // 듣지도 못한사람 목록 추가
    while(N--)
    {
        string a;
        cin >> a;
        d.insert(a);
    }


    int count = 0;
    
    set<string> b;
    while(M--)
    {
        string search;
        cin >> search;
        if(d.find(search)!=d.end())    //존재하면,
        {
            b.insert(search);
            count++;
        }
    }

    cout << count << "\n";
    
    for(auto element : b)
    {
        cout << element << "\n";
    }

    return 0;   
}