#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    
    unordered_map<string, int> map1;
    unordered_set<string> uni;
    
    for(int i = 0; i < str1.size()-1; i++) {
        if(('A' <= str1[i] && str1[i] <= 'Z') && ('A' <= str1[i+1] && str1[i+1] <= 'Z')) {
            string value = str1.substr(i, 2);
            map1[value]++;
        
            uni.insert(value);
        }
    }
    
    unordered_map<string, int> map2;
    
    for(int i = 0; i < str2.size()-1; i++) {
         if(('A' <= str2[i] && str2[i] <= 'Z') && ('A' <= str2[i+1] && str2[i+1] <= 'Z')) {
            string value = str2.substr(i, 2);
            map2[value]++;
        
            uni.insert(value);
        }
    }
    
    int unionCount = 0;
    int intersectCount = 0;
    
    for(auto& iter: uni) {
        intersectCount += min(map1[iter], map2[iter]);
        unionCount += max(map1[iter], map2[iter]);
    }
    
    cout << unionCount << '\t' << intersectCount << '\n';
    
    if(intersectCount == 0 && unionCount == 0) {
        return 1 * 65536;
    }
    
    return ((double) intersectCount / (double) unionCount) * 65536;
}