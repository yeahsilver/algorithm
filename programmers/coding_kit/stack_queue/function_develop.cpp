#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++) {
        q.push(progresses[i]);
    }
    
    while(!q.empty()) {
        
        for(int i = 0; i < q.size(); i++) {
            int progress = q.front();
            q.pop();
            q.push(progress+speeds[i]);
        }
        
        int cnt = 0;
        
        while(q.front() >= 100 && !q.empty()) {
            q.pop();
            speeds.erase(speeds.begin());
            cnt++;
        }
        
        if(cnt > 0) { 
            answer.push_back(cnt);
        }
    }
    
    return answer;
}