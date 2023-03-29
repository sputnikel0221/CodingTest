#include <iostream>
#include <map>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string name;
    int max = 0;

    // 가장 많이 팔린 책들을 담을 리스트
    list<string> bestseller;

    // 책 각각이 몇권 팔렸는지에 대한 map
    map<string, int> books;

    for (int i = 0; i < N; i++)
    {
        cin >> name;

        if (books.find(name) != books.end())
        {
            books[name]++;
        }
        else
        {
            books.insert({name, 1});
        }
    }

    //가장 많이 팔린 매수를 셈
    for (auto iter = books.begin(); iter != books.end(); iter++)
    {
        if (max <= iter->second)
        {
            max = iter->second;
        }
    }

    //가장 많이 팔린 매수에 해당하는 책들을 가져옴
    for (auto iter = books.begin(); iter != books.end(); iter++)
    {
        if (max == iter->second)
        {
            bestseller.push_back(iter->first);
        }
    }

    bestseller.sort();
    cout << bestseller.front();

    return 0;
}