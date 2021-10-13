#include <iostream>

using namespace std;

int main(void){
    int N;
    cin >>N;
    int cnt = 0, count = 0;

    for(int i = 1; i <= N; i++){
        int num = 0;
        cin >> num;

        for(int j = 1; j <=num; j++){
            if(num % j == 0){cnt++;}
        }
        if(cnt == 2) {count++;}
        cnt = 0;
    }
    cout<<count;
}