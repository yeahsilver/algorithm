#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 100001

bool visited[MAX];

int cnt;
int cycle[MAX];
int graph[MAX];

void DFS(int value) {
    visited[value] = true;

    int next = graph[value];

    if(!visited[next]) {
        DFS(next);

    } else if (!cycle[next]) {
        for(int i = next; i != value; i = graph[i]) {
            cnt++;
        }
        cnt++;
    }

    cycle[value] = true;
}

int main(void) {
    int test_case;
    cin >> test_case;

    while(test_case--) {
        memset(visited, false, sizeof(visited));
        memset(cycle, false, sizeof(cycle));

        cnt = 0;

        int N;
        cin >> N;

        for(int i = 1; i <= N; i++) {
            int input;
            cin >> input;

            graph[i] = input;
        }

        for(int i = 1; i <= N; i++) {
            if(!visited[i]) {
                DFS(i);
            }
        }

        cout << N-cnt << '\n';
    }
}