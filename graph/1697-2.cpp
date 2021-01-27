#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 100001

bool visited[MAX] = {0, };

int subin, dongsaeng;

int BFS(int subin, int depth) {
    queue<pair<int, int> > need_visit;
    need_visit.push(make_pair(subin, depth));
    visited[subin] = true;

    while(!need_visit.empty()) {
        int current = need_visit.front().first;
        int currentDepth = need_visit.front().second;

        need_visit.pop();

        if(current == dongsaeng) {
            return currentDepth;
        }
        
        if(current-1 >= 0 && !visited[current-1]) {
            int next = current-1;
            need_visit.push(make_pair(next, currentDepth+1));
            visited[next] = true;
        } 
        
        if(current + 1 < MAX && !visited[current+1]) {
            int next = current+1;
            need_visit.push(make_pair(next, currentDepth+1));
            visited[next] = true;
        }

        if(current * 2 < MAX && !visited[current * 2]) {
            int next = current * 2;
            need_visit.push(make_pair(next, currentDepth+1));
            visited[next] = true;
        }
    }
    return 0;
}

int main(void) {
    cin >> subin >> dongsaeng;

    cout << BFS(subin, 0) << '\n';

}