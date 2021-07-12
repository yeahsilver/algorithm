#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;

    while(cin >> num) {
        long long n = 1LL;
        
        int count = 1;

        while(n%num != 0) {
            n = ((n*10)+1)%num;
            count++;
        }
        cout << count << '\n';
    }
}