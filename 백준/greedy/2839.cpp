#include <iostream>

using namespace std;

int main(void){
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N;
	cin >> N;
	
	int three_kg = 0;
	int five_kg = 0;
	
	while(N % 5 != 0 && N >= 0){
		N-=3;
		three_kg++;
	}
	
	if(N<0){
		cout << -1 << '\n';	
	} else {
		five_kg = N/5;
		cout << three_kg + five_kg << '\n';
	}
}
