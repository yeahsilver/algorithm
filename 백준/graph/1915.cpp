#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1001

int main(void) {
    int N, M;
    cin >> N >> M;

    int graph[MAX][MAX];

    for(int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        
        for(int j = 0; j < s.size(); j++) {
            graph[i][j+1] = s[j]-'0';
        }
    }

    int maxValue = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(graph[i][j] != 0) {
                graph[i][j] = min(graph[i-1][j-1], min(graph[i-1][j], graph[i][j-1]))+1;
                maxValue = max(graph[i][j], maxValue);
            }
        }
    }

    cout << maxValue * maxValue << '\n';    
}