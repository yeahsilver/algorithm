#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    double* scores = new double[N+1];

    double maxValue = 0;

    for(int i = 0; i < N; i++) {
        double value;
        cin >> value;
        scores[i] = value;

        if(maxValue < value) maxValue = value;
    }

    double sum = 0;

    for(int i = 0; i < N; i++) {
        sum += scores[i]/maxValue*100;
    }

    printf("%f", sum/N);
}