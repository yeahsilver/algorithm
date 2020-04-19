#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N, max = 0, min = __INT_MAX__, sum = 0;
    cin>>N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin>>A[i];
    }
    for(int i = 0; i < N; i++){
        cin>>B[i];
    }

    sort(A.begin(), A.end(),greater<int>());
    sort(B.begin(), B.end());

    for(int i = 0; i <N; i++){
        sum+=A[i]*B[i];
    }
    cout<<sum;
}