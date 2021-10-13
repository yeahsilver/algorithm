#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int calculateMinDistance(char alphabet) {
    return alphabet -'A' > 1+('Z' - alphabet) ? 1+('Z' - alphabet): alphabet -'A';
}

int solution(string name) {
    int answer = 0;

    int movement = 0;
    int i = 0;
    
    bool isVisited[name.size()-1];

    memset(isVisited, false, name.size());

    for(int i = 0; i < name.size(); i++) {
        if(name[i] == 'A') {
            isVisited[i] = true;
            movement++;
        }
    }

    while(1) {
        if(movement == name.size()) {
            answer--;
            break;
        }
        
        isVisited[i] = true;

        // 'A' - name[i] 또는 name[i] - 'Z' 를 통해 알파벳의 거리 차이를 구해서 거리가 더 짧은 방법을 찾아서 answer에 추가 ==> 알파벳을 바꿀 때 조이스틱을 움직은 최소 값을 구함.
        answer += calculateMinDistance(name[i]);

        // 1. 첫번째 글자인 경우
        if(i == 0) {
            int nextDistance = calculateMinDistance(name[i+1]); 
            int lastDistance = calculateMinDistance(name[name.size()-1]);
     
            if(!isVisited[i+1] && !isVisited[name.size()-1]) {
                nextDistance > lastDistance ? i = name.size()-1 : i++;    

            } else if(isVisited[i+1]) {
                i = name.size()-1;

            } else if (isVisited[name.size()-1]) {
                i++;
            }

        } else if (i == name.size()-1) { // 2. 마지막인 경우.
            int firstDistance = calculateMinDistance(name[0]);
            int previousDistance =  calculateMinDistance(name[i-1]);
            
            if(!isVisited[0] && !isVisited[i-1]) {
                firstDistance > previousDistance ? i-- : i = 0;

            } else if(isVisited[i-1]) {
                i = 0;

            } else if (isVisited[0]) {
                i--;
            }
            
            
        } else {
            int previousDistance =calculateMinDistance(name[i-1]);
            int nextDistance = calculateMinDistance(name[i+1]);

            if(!isVisited[i-1] && !isVisited[i+1]) {
                previousDistance > nextDistance ? i++ : i--;     

            } else if(isVisited[i-1]) {
                i++;

            } else if (isVisited[i+1]) {
                i--;
            }
              
        }
        
        answer++;
        movement++;

    }
    return answer;
}

int main(void) {
    string name = "JEROEN";
    cout << solution(name) << '\n';
}