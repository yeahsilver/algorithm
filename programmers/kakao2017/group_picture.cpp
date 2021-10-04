#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool checkSign(char sign, int dist, int num) {
    if(sign == '=') {
        return dist == num;
    } else if(sign == '<') {
        return dist < num;

    } else if(sign == '>') {
        return dist > num;
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string friends = "ACFJMNRT";

    do {
        bool isSatisfied = true;

        for(int i = 0; i < data.size(); i++) {
            char one = data[i][0];
            char two = data[i][2];
            char sign = data[i][3];
            int num = data[i][4]-'0';

            int sub = friends.find(one) - friends.find(two);
            int dist = abs(sub)-1;

            if(checkSign(sign, dist, num)) {
                continue;
            }

            isSatisfied = false;
            break;
        }   
       
        if(isSatisfied) answer++;

    } while(next_permutation(friends.begin(), friends.end()));

    return answer;
}

int main(void) {
    int n = 2;
    vector<string> data;

    data.push_back("N~F=0");
    data.push_back("R~T>2");
    
    cout << solution(n, data) << '\n';
}
