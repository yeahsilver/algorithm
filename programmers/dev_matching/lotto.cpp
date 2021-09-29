#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int checkRanking(int correct) {
    if(correct == 6) {
        return 1;
    }    
    
    if(correct == 5) {
        return 2;
    }
    
    if(correct == 4) {
        return 3;
    }
    
    if(correct == 3) {
        return 4;
    }
    
    if(correct == 2) {
        return 5;
    }
    
    return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int removedNumberCount = 0;
    int correct = 0;
    
    for(auto& num: lottos) {
        if(num == 0) {
            removedNumberCount++;
            
        } else {
            auto it = find(win_nums.begin(), win_nums.end(), num);
            if(it != win_nums.end()) {
                correct++;
            }
        }
    }
    
    int highest = correct + removedNumberCount;
    
    answer.push_back(checkRanking(highest));
    answer.push_back(checkRanking(correct));
    
    return answer;
}