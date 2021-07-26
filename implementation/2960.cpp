#include <iostream>

using namespace std;

#define MAX 1001

int main(void) {

    int N, K;
    cin >> N >> K;

    int numbers[MAX] = {0, };

    int count = 0;
    int answer = 0;

    for(int i = 2; i <= N; i++) {
        if(numbers[i] == 0) {
            for(int j = 1; j*i <= N; j++) {
                if(numbers[i*j] == 0) {
                    
                    numbers[i*j] = 1;
                    count++;

                    if(count == K) {
                        answer = i*j;
                        break;
                    }   
                }                
            }
        }   
    }

    cout << answer << '\n';
}