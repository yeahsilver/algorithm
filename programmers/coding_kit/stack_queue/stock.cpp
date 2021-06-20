#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int i = 0; i < prices.size(); i++) {
        int cnt = 0;

        for(int j = i+1; j < prices.size(); j++) {
            if(prices[i] <= prices[j]) {
                cnt++;
            } else {
                cnt++;
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}

int main(void) {
    vector<int> price;
    price.push_back(1);
    price.push_back(2);
    price.push_back(3);
    price.push_back(2);
    price.push_back(3);

    vector<int> result = solution(price);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\t';
    }
}