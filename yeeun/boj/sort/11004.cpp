#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, k, n;
	cin >> N >>k;
	priority_queue<int,vector<int>,greater<> > pq;
	for(int i = 0; i < N; i++){
		cin>>n;
		pq.push(n);
		}
	while(k-- > 1){
		pq.pop();
		}
		cout << pq.top() << '\n';
	}
