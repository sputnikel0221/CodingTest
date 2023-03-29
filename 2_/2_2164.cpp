#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tmp;

    int N;
    cin >> N;

    queue<int> q;
 
	for (int i = 1; i <= N; ++i) {
		q.push(i);
	}
    cout << sizeof(q) << "\n";
 
	while (q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

    cout<<q.front();

    return 0;   
}