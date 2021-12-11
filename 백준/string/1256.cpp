#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M, K;
    cin >> N >> M >> K;

    string str = "";
    
    for(int i = 0; i < N; i++) {
        str.push_back('a');
    }

    for(int i = 0; i < M; i++) {
        str.push_back('z');
    }

    int count = 0;

    do {
        count++;
        
        if(count == K) {
            for(int i = 0; i < str.size(); i++) {
                cout << str[i];
            }

            return 0;
        }
       
    } while(next_permutation(str.begin(), str.end()));

    cout << -1 << '\n';
}
