#include <iostream>
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int alpha[26];  
    fill(alpha, alpha+26, -1);

    for(int i=0;i<s.length();i++)
    {
        if(alpha[s[i]-'a']==-1)
        {
            alpha[s[i]-'a'] = i;
        }
        else
        {
            continue;
        }
    }
    
    for(int i=0;i<26;i++)
    {
        cout << alpha[i] << " ";
    }

    return 0;   
}