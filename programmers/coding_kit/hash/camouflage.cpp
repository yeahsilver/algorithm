#include <string>
#include <vector>
#include <map>

using namespace std;

/*
    의상의 종류가 같은 것 끼리 하나의 배열에 넣기
    headgear: yellow hat, green turban
    eyewear: blue sunglasses
    
    경우의 수
    yellow hat
    green turban
    blue sunglasses 
    yellow hat + blue sunglasses
    green turban + blue sunglasses
*/

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> map;
    
    for(int i = 0; i < clothes.size(); i++) {
        string type = clothes[i][1];
        
        map[type]++;
    }
    
    std::map<string, int>::iterator it;
    
    for(it = map.begin(); it != map.end(); it++) {
        answer *= it-> second+1;
    }
    
    return answer-1;
}