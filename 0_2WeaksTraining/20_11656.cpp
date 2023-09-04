#include <iostream>
#include <set>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    set<string> se;
    for(int i=0;i<s.length();i++)
    {
        string tmp;
        tmp = s.substr(i, s.length());
        
        se.insert(tmp);
    }

    for(auto i:se)
    {
        cout << i << "\n";
    }
    return 0;   
}