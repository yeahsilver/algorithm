#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int A, B, V;
    cin >> A >> B >> V;

    int answer = (V-B)/(A-B);
    int quotient = (V-B)%(A-B);

    quotient != 0 ? cout << ++answer << '\n' : cout << answer << '\n';

    return 0;
}