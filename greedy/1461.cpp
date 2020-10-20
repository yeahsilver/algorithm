#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;

    vector<int> bookDistance(N);

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        bookDistance[i] = input;
    }

    sort(bookDistance.begin(), bookDistance.end());

    int diff = max(abs(bookDistance[0]), abs(bookDistance[N-1]));

    priority_queue<int> positive;
    priority_queue<int> negative;

    for(int i = 0; i < bookDistance.size(); i++){
        if(bookDistance[i]> 0){
            positive.push(bookDistance[i]);
        } else {
            negative.push(bookDistance[i]);
        }
    }

    int result = 0;

    while(!positive.empty()){
        result += positive.top();
        positive.pop();

        for(int i = 0; i < M-1; i++){
            if(!positive.empty()){
                positive.pop();
            }
        }
    }

    while(!negative.empty()){
        result += -negative.top();
        negative.pop();

        for(int i = 0; i < M-1; i++){
            if(!negative.empty()){
                negative.pop();
            }
        }
    }
    cout << (result*2)-abs(diff) << "\n";
}