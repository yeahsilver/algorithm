#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    unordered_set<int> l(lost.begin(), lost.end());
    unordered_set<int> inter;
    set<int> r;
    
    for(auto& value: reserve) {
        if(l.find(value) != l.end()) {
            inter.insert(value);
        } else {
            r.insert(value);
        }
    }
    
    for(auto& value: inter) {
        if(l.find(value) != l.end()) {
            l.erase(value);
        }
    }
    
    for(auto& value: r) {
        if(l.find(value-1) != l.end()) {
            l.erase(value-1);
        } else if(l.find(value+1) != l.end()) {
            l.erase(value+1);
        }
    }
       
    return n-l.size();
}
