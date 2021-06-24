#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {   
    int answer = 0, idx = 0;

    sort(people.begin(), people.end());

    while(people.size() > idx) {
        int back = people.back();
        people.pop_back();

        if(people[idx] + back <= limit) { 
            answer++;
            idx++;
        } else {
            answer++;
        }
    }

    return answer;
}

int main(void) {
    vector<int> people;

    people.push_back(70);
    people.push_back(50);
    people.push_back(80);
    people.push_back(50);

    int limit = 100;

    cout << solution(people, limit);

}