#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numbersString;

    for(auto& number: numbers) {
        numbersString.push_back(to_string(number));
    }
    
    sort(numbersString.begin(), numbersString.end(), compare);

    if(numbersString[0] == "0") {
        return "0";
    }

    for(int i = 0; i < numbersString.size(); i++) {
        answer+= numbersString[i];
    }
    
    return answer;
}

int main(void) {
    vector<int> numbers;
    // numbers.push_back(6);
    // numbers.push_back(10);
    // numbers.push_back(2);

    numbers.push_back(3);
    numbers.push_back(30);
    numbers.push_back(34);
    numbers.push_back(5);
    numbers.push_back(9);
    cout << solution(numbers) << '\n';
}