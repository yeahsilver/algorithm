#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int answer = N/5 + N/25 + N/125;

    cout << answer << '\n';
} 