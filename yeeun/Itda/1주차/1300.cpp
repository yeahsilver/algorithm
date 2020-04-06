// 런타임 에러
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N, k, n=1;
    cin >> N >> k;
    int** A = new int*[N];
    for(int i =1; i <=N; i++){
        A[i] = new int[N];
    }
    int* B = new int[N];

    for(int i = 1; i <=N; i++){
        for(int j = 1; j <=N; j++){
            A[i][j] = i*j;
            B[n] = A[i][j];
            n++;
        }
    }

    int* copyB = new int[n+1];
    for(int i = 1; i <=n; i++){
        copyB[i] = B[i];
    }
    sort(copyB, copyB+n);

    cout<<copyB[k];
}



