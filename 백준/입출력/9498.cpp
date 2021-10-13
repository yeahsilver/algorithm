#include <iostream>
using namespace std;

int main(void){
    int score;
    cin >> score;

    if(score <= 100 &&score >= 90) {
        cout << 'A' << '\n';
    } else if (score < 90 && score >= 80){
        cout << 'B' << '\n';
    } else if (score < 80 && score >= 70){
        cout << 'C' << '\n';
    } else if (score < 70 && score >= 60){
        cout << 'D' << '\n';
    } else {
        cout << 'F' << '\n';
    }
}