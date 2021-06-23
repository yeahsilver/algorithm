#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> numbersString;

    for(int i = 0; i < numbers.size(); i++) {
        numbersString.push_back(to_string(numbers[i]));
    }

    sort(numbersString.begin(), numbersString.end(), cmp);

    if(numbersString[0] == "0") {
        return "0";
    }

    for(int i = 0; i < numbersString.size(); i++) {
        answer += numbersString[i];
    }

    return answer;
}

int main(void) {
    vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(10);
    numbers.push_back(2);

    cout << solution(numbers) << '\n';
}