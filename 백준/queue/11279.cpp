#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	priority_queue<int> pq;
	
	for(int i = 0; i < N; i++) {
		int n;
		cin >> n;
		
		if(n == 0) {
			if(!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			} else {
				cout << 0 << '\n';
			}
		} else {
			pq.push(n);
		}
	}
}
