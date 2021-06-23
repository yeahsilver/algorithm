#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    1번 수포자 1 2 3 4 5 => 순서대로
    2번 수포자 2 1 2 3 2 4 2 5 2 1 2 3 ==> 홀수일 때 2 짝수일 때 1 3 5 (135 반복)
    3번 수포자 3 3 1 1 2 2 4 4 5 5 ==> (3 -> 1 -> 2 -> 4 -> 5)
*/

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> correct(3, 0);

    int first[5] = {1, 2, 3, 4, 5};
    int second[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int third[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for(int i = 0; i <answers.size(); i++) {
        if(first[i%5] == answers[i]) correct[0]++;
        if (second[i%8] == answers[i]) correct[1]++;
        if(third[i%10] == answers[i]) correct[2]++;
    }

    int maxValue = max(max(correct[0], correct[1]), correct[2]);

    for(int i = 0; i < correct.size(); i++) {
        if (maxValue == correct[i]) {
            answer.push_back(i+1);
        } 
    }

    return answer;
}

int main(void) {
    vector<int> answers;
    answers.push_back(1);
    answers.push_back(3);
    answers.push_back(2);
    answers.push_back(4);
    answers.push_back(2);

    vector<int> result = solution(answers);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
}