#include <iostream>
using namespace std;
#define num 5 //사이즈가 다르면 여기서 num 바꿔주세요 ㅠ0ㅠ 

int** createMatrix(int size){
    int** array;
    array = new int*[size+1];
    for(int i =0; i <= size;i++){
        array[i] = new int[size+1];
    }
    return array;
}//동적 배열 할당

int** initializeMatrix(int** matrix, int array[num][num]){
    for(int i=1; i<=num;i++){
        for(int j = 1; j<=num;j++){
            matrix[i][j] = array[i-1][j-1];
        }
    }
    return matrix;
}//정적배열을 동적배열으로 변환

void print(int **W){
    
    for(int i=1; i<=num;i++){
        for(int j = 1; j<=num;j++){
            if(W[i][j]==100) cout<<"oo ";
            else cout<<W[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}//배열을 출력해주는 함수

void path(int **P, int q, int r) {
   if (P[q][r]) { // P 배열에 값이 있을 경우
      path(P, q, P[q][r]);
      cout << "v" << P[q][r] << " ";//경로 출력
      path(P, P[q][r], r);
   }
}//경로를 계산해주는 함수

void floyd2(int n, int** W,int**& D, int** P) {
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         P[i][j] = 0;
      }
   } // 배열 초기화
   D = W;
   for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= n; j++) {
            if (D[i][j] > D[i][k] + D[k][j]) {
               P[i][j] = k;
               D[i][j] = D[i][k] + D[k][j];
            }
         }
      }
   }
}//Floyd 경로를 구하는 함수

int main(void){
    
   cout<<"====== 교재의 입력데이터 결과 값 ======"<<endl;
   int W[num][num]={{0,1,100,1,5},{9,0,3,2,100},{100,100,0,4,100},{100,100,2,0,3},{3,100,100,100,0}};
    int** copyW = initializeMatrix(createMatrix(num),W);
    int** D  = NULL; // 최단경로를 저장해주는 배열
    int** P = createMatrix(num); // 거쳐온 경로를 저장해주는 배열
    
    cout<<"초기값"<<endl;
    print(copyW);

   floyd2(5,copyW,D,P);
    
    cout<<"각각의 최단경로(가중치)"<<endl;
    print(D);
    cout<<endl;
    cout<<"P (거쳐온 경로)"<<endl;
    print(P);

    cout<<"v5에서"<<"v3까지의 최단경로 "<<endl;
    path(P,5,3);
    cout<<endl;
    cout<<endl;

   cout<<"====== 자작데이터 ======"<<endl;
   cout<<"데이터를 입력하세요 "<<endl;
      for(int i=0; i<num;i++){
        for(int j=0; j<num;j++){
            cin>>W[i][j];
        }
    }
    cout<<endl;
    
    int** copyW2 = initializeMatrix(createMatrix(num),W);
    int** D2  = NULL; // 최단경로를 저장해주는 배열
    int** P2 = createMatrix(num); // 거쳐온 경로를 저장해주는 배열
    
    cout<<"초기값"<<endl;
    print(copyW2);

   floyd2(4,copyW2,D2,P2);
    
   cout<<"각각의 최단경로(가중치)"<<endl;
   print(D2);
   cout<<endl;
   cout<<"P (거쳐온 경로)"<<endl;
   print(P2);
   cout<<"v1에서"<<"v3까지의 최단경로 "<<endl;
   path(P2,1,3);

// 자작데이터
// 0 5 100 8 5
// 7 0 9 100 100
// 2 100 0 4 100
// 100 100 3 0 3
// 100 100 5 4 0
    }
