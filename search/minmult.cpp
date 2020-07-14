#include <iostream>
#include <algorithm>
// 교재 데이터: 5 2 3 4 6 7 8
// 자작 데이터: 4 1 2 3 5 2 1

using namespace std;

void print(int **array,int num){
    
    for(int i=1; i<=num;i++){
        for(int j = 1; j<=num;j++){
            cout<<array[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";

}//배열을 출력해주는 함수

int** createMatrix(int n){  
    int** array;
    array = new int*[n+1];
    for(int i=1;i<=n;i++){
        array[i]=new int[n+1];
    }
    return array;
}//배열 생성

int** initializeMatrix(int n, int**array){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            array[i][j]=0;
        }
    }
    return array;
}// 배열 초기화

void order(int** P,int i,int j){
    if(i == j)
        cout<<"A"<<i<<"\t";
    else{
        int k = P[i][j];
        cout<<" ( ";
        order(P,i,k);
        order(P,k+1,j);
        cout<<" ) ";
    }
}//배열을 어떤 순서로 곱해야 최소로 곱셈이 이루어 지는지 알려주는 함수.

int minmult(int n, int* d,int** P){
    int** M = initializeMatrix(n+1,createMatrix(n+1));

    for(int diagonal = 1; diagonal<=n-1;diagonal++){
        for(int i=1;i<=n-diagonal;i++){
        int j = i+diagonal;
        M[i][j] = INT_MAX;
        for(int k = i;k<=j-1;k++){
            int m = M[i][k]+M[k+1][j]+(d[i-1])*(d[k])*(d[j]);
            if(m <M[i][j]){
                M[i][j] = m;
                P[i][j] = k;
            }
            }
        }
    }
    cout<<"M"<<"\n"; 
    print(M,n);// 배열 M 출력
    cout<<"P"<<"\n";
    print(P,n); // 배열 P 출력
   cout<<"\n";
    order(P,1,n); // 최소 곱셈 order 출력
    cout<<"\n";

    return M[1][n];
}

int main(void){
    int n;
    cout<<"개수를 입력하세요 ";
    cin>>n;
    int* d = new int[n+1];
    int** P = createMatrix(n+1);
    cout<<"\n";


    cout<<n<<"개의 배열의 행과 열의 갯수를 입력하세요"<<"\n";
    for(int i=0; i<=n;i++){
        cin>>d[i];
    }

    cout<< minmult(n,d,P)<<"번 곱셈할 때 가장 적게 곱해집니다.";// 최소 곱셈 횟수 출력
    return 0;
}