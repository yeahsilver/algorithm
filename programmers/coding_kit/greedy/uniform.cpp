#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
   int answer = 0;

    vector<int> students(n, 1);

    for(int i = 0; i < lost.size(); i++) {
        students[lost[i]-1]--;
    }

    for(int i = 0; i < reserve.size(); i++) {
        students[reserve[i]-1]++;
    }
    
    for(int i = 0; i < students.size(); i++) {
        if(students[i] == 0) {
            if(i != students.size()-1 && students[i+1] == 2) {
                students[i]++;
                students[i+1]--;
            } else if (i != students.size()-1 && students[i-1] == 2) {
                students[i]++;
                students[i-1]--;
            }
        }
    }

    for(int i = 0; i < students.size(); i++) {
        if (students[i] != 0) {
            answer++;
        }
    }

   return answer;
}

int main(void) {
    int n = 5;

    vector<int> lost;
    lost.push_back(2);
    lost.push_back(4);

    vector<int> reserve;
    reserve.push_back(1);
    reserve.push_back(3);
    reserve.push_back(5);

    cout << solution(n, lost, reserve);
}
