#include <iostream>

using namespace std;

#define PI 3.14159265359

int main(void) {
    double num;
    cin >> num;

    double euclid = num * num * PI;
    double taxi = num*num*2.0;

    printf("%.6f\n", euclid);
    printf("%.6f\n", taxi);
}