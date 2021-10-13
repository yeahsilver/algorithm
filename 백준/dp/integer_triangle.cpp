#include <string>
#include <vector>

using namespace std;

#define MAX 501

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    
    int dp[MAX][MAX];
    
    dp[0][0] = triangle[0][0];
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < i+1; j++) {
            if(j == 0) {
                dp[i][j] = dp[i-1][0] + triangle[i][0];
                
            } else if(i == j) {
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                
            } else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    
    for(int i = 0; i < size; i++) {
        if (answer < dp[size-1][i]) {
            answer = dp[size-1][i];
        }
    }
    
    return answer;
}