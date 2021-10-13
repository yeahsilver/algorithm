#include <iostream>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int test_case;
    cin >> test_case;

    while(test_case--){
        int a, b;
        cin >> a >> b;
        cout << a + b << '\n';
    }
}