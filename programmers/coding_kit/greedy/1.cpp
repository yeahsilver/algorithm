#include <string>
#include <vector>

using namespace std;

#define MAX 31

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int array[MAX] = {0, };
    
    for(int i = 1; i <= n; i++) {
        array[i] = 1;
    }
    
    for(auto& number: reserve) {
        array[number]++;
    }
    
    for(auto& number: lost) {
        array[number]--;
    }
    
    for(int i = 1; i <= n; i++) {
        if(array[i] == 0) {
            if(i != 1 && array[i-1] > 1) {
                array[i]++;
                array[i-1]--;
                
            } else if(i != n && array[i+1] > 1){
                array[i]++;
                array[i+1]--;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(array[i] > 0) {
            answer++;
        }
    }
    
    return answer;
}
