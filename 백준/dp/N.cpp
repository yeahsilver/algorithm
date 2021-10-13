#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

#define MAX 8

int minDepth = MAX+1;

void dfs(int N, int number, int depth, int sum) {
    // 8번 이상 진행하였으면 return 
    if(depth > MAX) {
        return;
    }    
    
    // sum값이 목표 값 (number)와 같으면 그 중 작은 depth 비교
    if(sum == number) {
        minDepth = min(depth, minDepth);
        return;
    }
    
    int operand = 0;
    for(int i = 1; i <= MAX; i++) {
        operand = operand * 10 + N;
        
        dfs(N, number, depth + i, sum + operand);
        dfs(N, number, depth + i, sum - operand);
        dfs(N, number, depth + i, sum * operand);
        
        if(sum != 0) {
            dfs(N, number, depth+1, sum / operand);
        }
    }
}

int solution(int N, int number) {
    int answer = 0;
    
    dfs(N, number, 0, 0);
    
    answer = (minDepth > MAX) ? -1 : minDepth;
    
    return answer;
}