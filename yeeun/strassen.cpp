#include <iostream>
using namespace std;
int** createMatrix(int size){
    int** array;
    array = new int*[size];
    for(int i=0; i<size;i++){
        array[i]=new int[size];
    }
    return array;
}// 배열 동적 할당

int** Matrix(int** matrix, int array[4][4]){
    for(int i =0; i<4;i++){
        for(int j=0; j<4;j++){
            matrix[i][j] = array[i][j];
        }
    }
    return matrix;
    
} //정적 배열을 동적 배열의 형태로 만들어줌 

int** addMatrix(int** A, int** B, int n){
    int** C =createMatrix(n);
    for(int i = 0; i<n;i++){
        for(int j=0; j<n;j++){
            C[i][j] = A[i][j]+B[i][j];
        }
    }
    return C;
}//더하기 연산

int** subMatrix(int** A, int**B, int n){
    int** C =createMatrix(n);
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            C[i][j]=A[i][j]-B[i][j];
        }
    }
    return C;
}// 빼기 연산

int** mulMatrix(int** A, int**B, int n){
    int** C =createMatrix(n);
    for(int i=0; i<n;i++){
        for(int j = 0; j<n;j++){
            C[i][j] = A[i][j]*B[i][j];
        }
    }
    return C;}// 곱셈 연산

int** divideMatrix(int** A, int position, int n){
    int **a11 = createMatrix(n);
    int **a12 = createMatrix(n);
    int **a21 = createMatrix(n);
    int **a22 = createMatrix(n);

    for (int i=0; i<n;i++){
        for (int j=0; j<n;j++){
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j+n];
            a21[i][j] = A[i+n][j];
            a22[i][j] = A[i+n][j+n];        
        }
    }

    if(position == 11) return a11;
    else if(position == 12) return a12;
    else if(position == 21) return a21;
    else if(position == 22) return a22;
    else return NULL;

}// 행렬 분할

int** combineMatrix(int** C1, int** C2,int** C3, int** C4, int n){
    int** C  = createMatrix(n);
    int m = n/2;
    for(int i = 0; i<m;i++){
        for(int j = 0; j<m;j++){
            C[i][j]=C1[i][j];
            C[i][j+m] = C2[i][j];
            C[i+m][j] = C3[i][j];
            C[i+m][j+m] = C4[i][j];
        }
    }
    return C;
} // 행렬 합병

void strassen(int n, int** A, int** B, int** &C){
    if(n <= 1) {C = mulMatrix(A,B,n); return; }
    else {
        int **m1 = createMatrix(n/2);
        int **m2 = createMatrix(n/2);
        int **m3 = createMatrix(n/2);
        int **m4 = createMatrix(n/2);
        int **m5 = createMatrix(n/2);
        int **m6 = createMatrix(n/2);
        int **m7 = createMatrix(n/2);
        //m1~m7까지 공간 할당
        int** A11 = divideMatrix(A,11,n/2);
        int** A12 = divideMatrix(A,12,n/2);
        int** A21 = divideMatrix(A,21,n/2);
        int** A22 = divideMatrix(A,22,n/2);
        int** B11 = divideMatrix(B,11,n/2);
        int** B12 = divideMatrix(B,12,n/2);
        int** B21 = divideMatrix(B,21,n/2);
        int** B22 = divideMatrix(B,22,n/2);
        //A11~A22, B11~B22로 배열 나누기
        
        strassen(n/2,addMatrix(A11,A22,n/2),addMatrix(B11,B22,n/2),m1);
        strassen(n/2,addMatrix(A21,A22,n/2),B11,m2);
        strassen(n/2,A11,subMatrix(B12,B22,n/2),m3);
        strassen(n/2,A22,subMatrix(B21,B11,n/2),m4);
        strassen(n/2,addMatrix(A11,A12,n/2),B22,m5);
        strassen(n/2,subMatrix(A21,A11,n/2),addMatrix(B11,B12,n/2),m6);
        strassen(n/2,subMatrix(A12,A22,n/2),addMatrix(B21,B22,n/2),m7);
        //strassen 함수  

        int **C1 = createMatrix(n/2);
        int **C2 = createMatrix(n/2);
        int **C3 = createMatrix(n/2);
        int **C4 = createMatrix(n/2);
        //계산 값을 넣을 C1~C4 배열 할당
        
        C1 = addMatrix(m1,m4,n/2);
        C1 = subMatrix(C1,m5,n/2);
        C1 = addMatrix(C1,m7,n/2);
        //C1 = m1+m4-m5+m7

        C2 = addMatrix(m3,m5,n/2);
        //C2 = m3+m5

        C3 = addMatrix(m2,m4,n/2);
        //C3 = m2+m4

        C4 = addMatrix(m1,m3,n/2);
        C4 = subMatrix(C4,m2,n/2);
        C4 = addMatrix(C4,m6,n/2);
        //C4 = m1+m3-m2+m6


        C = combineMatrix(C1,C2,C3,C4,n);
        //C1~C4의 값을 합치기
    }    
}

int main(void){
    //int A[4][4]={{1,2,3,4},{5,6,7,8},{9,1,2,3},{4,5,6,7}};
    int A[4][4]={{1,0,1,0},{0,1,0,1},{1,0,1,0},{0,1,0,1}};//자작 데이터

    //int B[4][4]={{8,9,1,2},{3,4,5,6},{7,8,9,1},{2,3,4,5}};
    int B[4][4]={{0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0}};//자작 데이터
    
    int** C = createMatrix(4);

    int** copyA = Matrix(createMatrix(4),A);
    int** copyB = Matrix(createMatrix(4),B);

    strassen(4,copyA,copyB,C);
    
    for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }// 결과값 출력
}