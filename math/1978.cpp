#include <iostream>

using namespace std;

int main(void) {
    int num;
    cin >> num;

    int answer = 0;
    for(int i = 0; i < num; i++) {
        int value;
        cin >> value;

        int cnt = 0;

        for(int i = 1; i <= value; i++) {
            if(value%i == 0) {
                cnt++;
            }
        }

        if(cnt == 2) {
            answer++;
        }
    }

    cout << answer << '\n';
}