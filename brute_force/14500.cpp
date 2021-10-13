#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 501

int main(void) {
    int M, N;
    cin >> N >> M;

    vector<int> graph[MAX];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int value;
            cin >> value;
            graph[i].push_back(value);
        }
    }

    int maxSum = 0;
    // 1. **** 인 경우
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= M-4; j++) {
            int sum = 0;
            for(int k = j; k < j+4; k++) {
                sum += graph[i][k];
            }

            maxSum = max(sum, maxSum);
        }
    }

    /* 2.
        *
        *
        * 
        *  인 경우
    */

   for(int i = 0; i <= N-4; i++) {
        for(int j = 0; j < M; j++) {
            int sum = 0;
            for(int k = i; k < i+4; k++) {
                
                sum += graph[k][j];
            }
            maxSum = max(sum, maxSum);
        }
    }

    /* 3.
        *
        *
        * * 인 경우
    */

    for(int i = 0; i <= N-3; i++) {
        for(int j = 0; j < M-1; j++) {
            int sum = 0;
            for(int k = i; k < i+3; k++) {
                if(k == i+2) {
                    sum += graph[k][j+1];
                }
                sum += graph[k][j];
            }
            maxSum = max(sum, maxSum);
        }
    }

    // 대칭
    for(int i = 0; i <= N-3; i++) {
        for(int j = 1; j < M; j++) {
            int sum = 0;
            for(int k = i; k < i+3; k++) {
                if(k == i+2) {
                    sum += graph[k][j-1];
                }
                sum += graph[k][j];
            }
            maxSum = max(sum, maxSum);
        }
    }

    /* 4.
    * *
      *  
      * 인 경우
    */

    for(int i = 0; i <= N-3; i++) {
        for(int j = 0; j < M-1; j++) {
            int sum = 0;
            for(int k = i; k < i+3; k++) {
                if(k == i) {
                    sum += graph[k][j+1];
                }
                sum += graph[k][j];
            }
            maxSum = max(sum, maxSum);
            
        }
    }

    // 대칭
    for(int i = 0; i <= N-3; i++) {
        for(int j = 1; j < M; j++) {
            int sum = 0;
            for(int k = i; k < i+3; k++) {
                if(k == i) {
                    sum += graph[k][j-1];
                }
                sum += graph[k][j];
            }
            maxSum = max(sum, maxSum);
        }
    }

    /* 5.
        *** 인 경우
        *
    */

    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j <= M-3; j++) {
            int sum = 0;
            for(int k = j; k < j+3; k++) {
                if(k == j) {
                    sum += graph[i+1][k];
                }
                sum += graph[i][k];
            }
            maxSum = max(sum, maxSum);
        }
    }

    // 대칭
    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= M-3; j++) {
            int sum = 0;
            for(int k = j; k < j+3; k++) {
                if(k == j) {
                    sum += graph[i-1][k];
                }
                sum += graph[i][k];
            }
            maxSum = max(sum, maxSum);
        }
    }
    
    /* 6.
          *
        *** 인 경우
    */

    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= M-3; j++) {
            int sum = 0;
            for(int k = j; k < j+3; k++) {
                if(k == j+2) {
                    sum += graph[i-1][k];
                }
                sum += graph[i][k];
            }
            maxSum = max(sum, maxSum);
        }
    }

    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j <= M-3; j++) {
            int sum = 0;
            for(int k = j; k < j+3; k++) {
                if(k == j+2) {
                    sum += graph[i+1][k];
                }
                sum += graph[i][k];
            }
            maxSum = max(sum, maxSum);
        }
    }

    /* 7.
        **
        ** 인 경우
    */

    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j <= M-2; j++) {
            int sum = 0;
            for(int k = j; k < j+2; k++) {
                sum += graph[i][k];
                sum += graph[i+1][k];
            }
            maxSum = max(sum, maxSum);
        }
    }

    /* 8.
         **
        ** 인 경우
    */

    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j <= M-3; j++) {
            int sum = 0;
            for(int k = j; k < j+3; k++) {
                if(k == j) {
                    sum += graph[i+1][k];
                } else if(k == j+2) {
                    sum += graph[i][k];
                } else {
                    sum += graph[i][k];
                    sum += graph[i+1][k];
                }   
            }
            maxSum = max(sum, maxSum);
        }
    }

    // 대칭
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j <= M-3; j++) {
            int sum = 0;
            for(int k = j; k < j+3; k++) {
                if(k == j) {
                    sum += graph[i][k];
                } else if(k == j+2) {
                    sum += graph[i+1][k];
                } else {
                    sum += graph[i][k];
                    sum += graph[i+1][k];
                }   
            }
            maxSum = max(sum, maxSum);
        }
    }

    /* 9.
        *
        **
         * 인 경우
    */

    for(int i = 1; i < N-1; i++) {
        for(int j = 0; j <= M-2; j++) {
            int sum = 0;
            for(int k = j; k < j+2; k++) {
                if(k == j) {
                    sum += graph[i-1][k];
                } 
                
                if(k == j+1) {
                    sum += graph[i+1][k];
                }   

                sum += graph[i][k];
            }
            maxSum = max(sum, maxSum);
        }
    }

    // 대칭
    for(int i = 1; i < N-1; i++) {
        for(int j = 0; j <= M-2; j++) {
            int sum = 0;
            for(int k = j; k < j+2; k++) {
                if(k == j) {
                    sum += graph[i+1][k];
                } 
                
                if(k == j+1) {
                    sum += graph[i-1][k];
                }   

                sum += graph[i][k];
            }
            maxSum = max(sum, maxSum);
        }
    }

    /*
        10 
         *
        ***
    */

    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= M-3; j++) {
            int sum = 0;
            for(int k = j; k < j+3; k++) {
                if(k == j+1) {
                    sum += graph[i-1][k];
                }

                sum += graph[i][k];
            }
            maxSum = max(sum, maxSum);
        }
    }

    /*
        11
        ***
         *
    */

    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j <= M-3; j++) {
            int sum = 0;
            for(int k = j; k < j+3; k++) {
                if(k == j+1) {
                    sum += graph[i+1][k];
                }

                sum += graph[i][k];
            }
            maxSum = max(sum, maxSum);
        }
    }

    /* 12.
        *
        * *
        *   인 경우
    */

   for(int i = 0; i <= N-3; i++) {
        for(int j = 0; j < M-1; j++) {
            int sum = 0;
            for(int k = i; k < i+3; k++) {
                if(k == i+1) {
                    sum += graph[k][j+1];
                }
                sum += graph[k][j];
            }
            maxSum = max(sum, maxSum);
        }

    }

    /* 13.
         *
        ** 
         *   인 경우
    */

   for(int i = 0; i <= N-3; i++) {
        for(int j = 1; j < M; j++) {
            int sum = 0;
            for(int k = i; k < i+3; k++) {
                if(k == i+1) {
                    sum += graph[k][j-1];
                }
                sum += graph[k][j];
            }
            maxSum = max(sum, maxSum);
        }
    }
    cout << maxSum << '\n';
}