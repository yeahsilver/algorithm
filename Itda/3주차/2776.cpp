//왜 틀린건지 모르겠어요.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T, N, M;
	cin >> T >> N;
	vector<vector<int> > one(T,vector<int>(N,0));
	
	for(int i =0; i <T; i++){
		for(int j = 0; j < N; j++){
			cin >> one[i][j];
		}
	}
	
	for(int i = 0; i <T; i++){
		sort(one[i].begin(), one[i].end());
	}
	
	cin>> M;
	vector<vector<int> > two(T,vector<int>(M,0));
	
	for(int i =0; i <T; i++){
		for(int j = 0; j < N; j++){
			cin >> two[i][j];
		}
	}
	
	for(int i = 0; i < T; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				if(two[i][j] == one[i][k]){
					printf("1\n");
					break;
				}else if(k== M-1 && two[i][j] != one[i][k]){
					printf("0\n");
				}
				
			}
		}
	}	
}