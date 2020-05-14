
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(void){
	int n, first, second;
	cin >> n;
	vector<pair<int, int> > v;
	
	for(int i = 0; i < n; i++){
		cin >> first >> second;
		v.push_back(make_pair(second,first));
	}
	
	sort(v.begin(), v.end());
	int cnt = 0;
	int temp = 0; // 시간을 갱신해주는 변수
	
	for(int i = 0; i < n; i++){
		int beginTime = v[i].second;
		int endTime = v[i].first; 
		if(temp <= beginTime){ // beginTime이 더 큰 경우
			temp = endTime; // 다음 비교를 위해 temp에 endTime을 저장해줌
			cnt++;
		}
	}
	
	cout << cnt;
}
