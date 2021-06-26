#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int> > factors;

bool isRectangle(int a, int b, int yellow) {
    if((a-2) * (b-2) == yellow) return true;

    return false;
}

void factor(int n, int yellow) {
    if(n <= 0) {
        return ;
    }

    for(int i = 1; i*i <= n; i++) {
        if(i*i == n) {
            if(isRectangle(i, i, yellow)) {
                factors.push_back(make_pair(i, i));
            }

        } else if(n%i == 0) {
            if(isRectangle(n/i, i, yellow)) {
                factors.push_back(make_pair(n/i, i));
            }
        }
    }
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    factor(brown+yellow, yellow);

    int size = factors.size()-1;
    answer.push_back(factors[size].first);
    answer.push_back(factors[size].second);

    return answer;
}

int main(void) {
    int brown = 50;
    int yellow = 22;

   vector<int> result = solution(brown, yellow);

   for(int i = 0; i < factors.size(); i++) {
       cout << factors[i].first << '\t' << factors[i].second << '\n';
   }

   cout << '\n';

   for(int i = 0; i < result.size(); i++) {
       cout << result[i] << '\n';
   }
}