#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 101

vector<int> solution(int rows, int columns, vector<vector<int> > queries) {
    vector<int> answer;

    int count = 1;
    vector<int> graph[MAX];

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            graph[i].push_back(count);
            count++;
        }
    }

    for(auto& query: queries) {
        
        int x1 = query[0]-1;
        int y1 = query[1]-1;
        int x2 = query[2]-1;
        int y2 = query[3]-1;

        // 지역 변수 선언
        int prev = graph[x1][y1];
        int next;
        int minValue = __INT_MAX__;

        // 1. 오른쪽으로 이동 (x1 고정)
        for(int i = y1+1; i <= y2; i++) {
            next = graph[x1][i];
            graph[x1][i] = prev;

            minValue = min(prev, minValue);
            prev = next;
        }

        // 2. 아래쪽으로 이동 (y2 고정)
        for(int i = x1+1; i <= x2; i++) {

            next = graph[i][y2];
            graph[i][y2] = prev;

            minValue = min(prev, minValue);

            prev = next;
        }

        // 3. 왼쪽으로 이동 (x2 고정)

        for(int i = y2-1; i >= y1; i--) {
            next = graph[x2][i];
            graph[x2][i] = prev;

            minValue = min(prev, minValue);

            prev = next;
        }

        // 4. 위쪽으로 이동 (y1 고정)
        for(int i = x2-1; i >= x1; i--) {
            next = graph[i][y1];
            graph[i][y1] = prev;

            minValue = min(prev, minValue);

            prev = next;
        }

        answer.push_back(minValue);
    }
    return answer;
}

int main(void) {
    int rows = 6;
    int columns = 6;

    // int rows = 3;
    // int columns = 3;

    // int rows = 10;
    // int columns = 7;

    vector<vector<int> > queries;
    
    vector<int> query;
    // query.push_back(1);
    // query.push_back(1);
    // query.push_back(10);
    // query.push_back(7);

    // queries.push_back(query);

    query.push_back(2);
    query.push_back(2);
    query.push_back(5);
    query.push_back(4);

    // query.push_back(1);
    // query.push_back(1);
    // query.push_back(2);
    // query.push_back(2);

    queries.push_back(query);
    query.clear();

    query.push_back(3);
    query.push_back(3);
    query.push_back(6);
    query.push_back(6);
    
    // query.push_back(1);
    // query.push_back(2);
    // query.push_back(2);
    // query.push_back(3);

    queries.push_back(query);
    query.clear();

    query.push_back(5);
    query.push_back(1);
    query.push_back(6);
    query.push_back(3);
    
    // query.push_back(2);
    // query.push_back(1);
    // query.push_back(3);
    // query.push_back(2);

    queries.push_back(query);
    query.clear();

    // query.push_back(2);
    // query.push_back(2);
    // query.push_back(3);
    // query.push_back(3);

    // queries.push_back(query);


    vector<int> result = solution(rows, columns, queries);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\t';
    }
}