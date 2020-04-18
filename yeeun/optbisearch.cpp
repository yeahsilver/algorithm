#include <iostream>
using namespace std;
//교재 데이터: 0.375 0.375 0.125 0.125
//자작 데이터 : 0.1 0.2 0.3 0.4

float sum(float *arr, int start, int end){
    float sum = 0;
    for(int i=start; i<end+1; i++){
        sum += arr[i];
    }
    return sum;
}

void optsearchtree(int n, float* p, float minavg, int** R){
    float **A = new float* [n+2];
    for(int i=0; i<=n+1;i++){
        A[i] = new float[n+1];
    }

    for(int i=1; i<=n; i++){
        A[i][i-1] = 0;
        A[i][i] = p[i];
        R[i][i] = i;
        R[i][i-1] = 0;
    }
    A[n+1][n] = 0; R[n+1][n] =0;

    for(int diagonal = 1; diagonal <= n-1; diagonal++){
        for(int i=1; i<=n-diagonal;i++){
        int j = i + diagonal;
                A[i][j] = __FLT_MAX_EXP__;

        for (int k=i; k<=j; k++){
            float m = A[i][k-1]+A[k+1][j]+sum(p,i,j);
            if(m < A[i][j]){
                A[i][j] = m;
                R[i][j] = k;
                }
            }   
        }
    }

    cout<<"A\n";
    for(int i=1;i<=n;i++){
        for(int j = 0; j<=n;j++)
            cout<<A[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\n";
    minavg = A[1][n];
}

int main(void){
    int n;
    cout<<"배열의 개수를 입력하세요: "<<"\n";
    cin>>n;

    int** R = new int*[n+2];
    for(int i=0; i<=n+1;i++){
        R[i] = new int[n+1];
    }

    float* p = new float[n+1];

    cout<<"p의 값을 입력하세요"<<endl;
    for(int i=1; i<=n;i++){
        cin>>p[i];
    }

    float minavg;
    
    optsearchtree(n,p,minavg,R);
    cout<<"R"<<"\n";
    for(int i =1; i<=n+1;i++){
        for(int j = 0; j<=n;j++){
            cout<<R[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
