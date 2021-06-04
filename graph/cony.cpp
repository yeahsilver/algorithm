#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 200001

int cony, brown;

int bfs(int brown) {
    queue<pair<int, int> > need_visit;
    int visited[MAX] = {0, };

    need_visit.push(make_pair(brown, 0));
    visited[brown] = true;

    bool flag = false;
    int time = 0;
    while(!need_visit.empty()) {

        int current = need_visit.front().first;
        int depth = need_visit.front().second;

        if(depth == time) {
            flag = true;
        } else {
            flag = false;
            time = depth;
        }

        if(!flag) {
            cony += depth;
        }

        need_visit.pop();

        if(cony == current) {
            return depth;
        }

        if(cony > 200000) {
            return -1;
        }
        
        if(current-1 >=0 && !visited[current-1]) {
            need_visit.push(make_pair(current-1, depth+1));
            visited[current-1] = true;
        }

        if(current+1 >= 0 && !visited[current+1]) {
            need_visit.push(make_pair(current+1, depth+1));
            visited[current+1] = true;
        }

        if(current * 2 >= 0 && !visited[current * 2]) {
            need_visit.push(make_pair(current * 2, depth+1));
            visited[current * 2] = true;
        }
    }

    return -1;
}

int main(void) {
    cin >> cony >> brown;

    cout << bfs(brown);
}