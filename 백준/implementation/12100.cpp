#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 21

enum position {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

int maxNum = 0;
int N;

void calculateMax(vector<int>* graph) {

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            maxNum = max(maxNum, graph[i][j]);
        }
    }
}

void move(int depth, int position, vector<int>* graph) {
    if(depth == 5) {
        return;
    }

    if(position == UP) {
        bool isVisited[MAX][MAX] = {false, };

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(graph[i][j] == 0) {
                    continue;
                }
                
                for(int k = i; k > 0; k--) {
                    if(graph[k-1][j] == 0) {
                        graph[k-1][j] = graph[k][j];
                        graph[k][j] = 0;
                        isVisited[k-1][j] = isVisited[k][j];
                        isVisited[k][j] = false;

                    } else {
                        if(graph[k-1][j] == graph[k][j] && !isVisited[k-1][j]) {
                            graph[k-1][j] *= 2;
                            graph[k][j] = 0;
                            isVisited[k-1][j] = true;
                        } 
                        break;
                    }
                }
            }
        }

        calculateMax(graph);
    }

    if(position == DOWN) {
        bool isVisited[MAX][MAX] = {false, };

        for(int i = N-1; i > 0; i--) {
            for(int j = N-1; j >= 0; j--) {
                if(graph[i][j] == 0) {
                    continue;
                }
                
                for(int k = i; i < N-1; k++) {
                    if(graph[k+1][j] == 0) {
                        graph[k+1][j] = graph[k][j];
                        graph[k][j] = 0;
                        isVisited[k+1][j] = isVisited[k][j];
                        isVisited[k][j] = false;

                    } else {
                        if(graph[k+1][j] == graph[k][j] && !isVisited[k+1][j]) {
                            graph[k+1][j] *= 2;
                            graph[k][j] = 0;
                            isVisited[k+1][j] = true;
                        }
                        break; 
                    }
                }
            }
        }

        calculateMax(graph);
    }

    if(position == LEFT) {
      bool isVisited[MAX][MAX] = {false, };

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(graph[i][j] == 0) {
                    continue;
                }
                
                for(int k = j; k > 0; k--) {
                    if(graph[i][k-1] == 0) {
                        graph[i][k-1] = graph[i][k];
                        graph[i][k] = 0;
                        isVisited[i][k-1] = isVisited[i][k];
                        isVisited[i][k] = false;

                    } else {
                        if(graph[i][k-1] == graph[i][k] && !isVisited[i][k-1]) {
                            graph[i][k-1] *= 2;
                            graph[i][k] = 0;
                            isVisited[i][k-1] = true;
                        } 
                        break;
                    }
                }
            }
        }

        calculateMax(graph);
    }

    if(position == RIGHT) {
        bool isVisited[MAX][MAX] = {false, };

        for(int i = N-1; i >= 0; i--) {
            for(int j = N-1; j > 0; j--) {
                if(graph[i][j] == 0) {
                    continue;
                }
                
                for(int k = j; k < N-1; k++) {
                    if(graph[i][k+1] == 0) {
                        graph[i][k+1] = graph[i][k];
                        graph[i][k] = 0;
                        isVisited[i][k+1] = isVisited[i][k];
                        isVisited[i][k] = false;

                    } else {
                        if(graph[i][k+1] == graph[i][k] && !isVisited[i][k+1]) {
                            graph[i][k+1] *= 2;
                            graph[i][k] = 0;
                            isVisited[i][k+1] = true;
                        } 
                        break;
                    }
                }
            }
        }

        calculateMax(graph);
    }

    move(depth+1, UP, graph);
    move(depth+1, DOWN, graph);
    move(depth+1, LEFT, graph);
    move(depth+1, RIGHT, graph);
}

int main(void) {
    cin >> N;
    
    vector<int> graph[MAX];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int value;
            cin >> value;
            graph[i].push_back(value);
        }
    }

    if(N == 1) {
        cout << graph[0][0] << '\n';
        return 0;
    }
    
    move(0, UP, graph);
    move(0, DOWN, graph);
    move(0, LEFT, graph);
    move(0, RIGHT, graph);

    cout << maxNum << '\n';
    return 0;
}