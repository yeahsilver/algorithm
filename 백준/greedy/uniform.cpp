#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> state(n);
    
    for(int i = 0; i < lost.size(); i++) {
        int idx = lost[i]-1;
        state[idx] -= 1;
    }
    
    for(int i = 0; i < reserve.size(); i++) {
        int idx = reserve[i]-1;
        state[idx] +=1;
    }
    
    for(int i = 1; i < state.size(); i++) {
        if(i == state.size()-1) {
            if (state[i-1] == 1) {
                state[i]+=1;
                state[i-1]-=1;
            }
            break;
        }
        
        if(state[i] == -1) {
            if(state[i-1] == 1) {
                state[i]+=1;
                state[i-1]-=1;
            } else if (state[i+1] == 1) {
                state[i]+=1;
                state[i+1]-=1;
            }
        }
    }
                      
    for(int i = 0; i <state.size(); i++) {
        if(state[i] >= 0) answer++;
    }
    
    return answer;
}

int main(void) {
    // int n = 5;
    int n = 3;

    vector<int> lost;
    // lost.push_back(2);
    // lost.push_back(4);

    lost.push_back(3);

    vector<int> reserve;
    // reserve.push_back(1);
    // reserve.push_back(3);
    // reserve.push_back(5);

    // reserve.push_back(3);

    reserve.push_back(1);

    cout << solution(n, lost, reserve) << '\n';
}