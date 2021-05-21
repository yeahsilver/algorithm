#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define for(i, start, end) for(int i = start; i < end; i++)

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    sort(stages.begin(), stages.end());
    
    vector<double> failure;

    int i = 1;
    
    while(i <= N) {
        int a = upper_bound(stages.begin(), stages.end(), i) - lower_bound(stages.begin(), stages.end(), i);
        int b = stages.end() - lower_bound(stages.begin(), stages.end(), i);

        double value = (double) a/b;

        if(a == 0 && b == 0) {
            failure.push_back(0);
        } else {
            failure.push_back((double)a/b);
        }
        
        i++;
    }

    
    for(i, 0, failure.size()) {
        int maxIndex = max_element(failure.begin(), failure.end()) - failure.begin();

        answer.push_back(maxIndex+1);
        
        failure[maxIndex] = -1;
    }

    return answer;
}