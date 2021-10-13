#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string A, B;
    cin >> A >> B;

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    if(stoi(A) < stoi(B)) {
        cout << stoi(B) << '\n';
    } else {
        cout << stoi(A) << '\n';
    }
}