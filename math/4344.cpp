#include <iostream>

using namespace std;

int main(void) {

    int testCase;
    cin >> testCase;

    while(testCase--) {
        int numberOfStudents;
        cin >> numberOfStudents;

        double* scores = new double[numberOfStudents+1];

        double sum = 0;
        for(int i = 0; i < numberOfStudents; i++) {
            cin >> scores[i];
            sum += scores[i];
        }
        
        double average = sum/numberOfStudents;

        int count = 0;

        for(int i = 0; i < numberOfStudents; i++) {
            if(scores[i] > average) {
                count++;
            }
        }

        printf("%.3f%%\n", (double(count) / numberOfStudents) * 100);        
    }
}