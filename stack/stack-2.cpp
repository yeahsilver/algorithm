#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int weight_now = 0;
    int finish_time = 0;
    
    queue<int> enter_truck, truck;
    int N = truck_weights.size();
    
    for(int i =0; i < truck_weights.size(); i++){
        truck.push(i) = truck_weights[i];
    }
    
    for(int i = 0; i < N; i++){
        if(truck.size() > 0){
            if(i - truck.front() == bridge_length){
                
            }
        }
    }
   
    
    return answer;
}

int main(void){
    int sec = solution(2,10,{7,4,5,6});
    cout<<sec;
}