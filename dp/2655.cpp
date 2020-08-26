#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Brick{
    int number;
    int area;
    int height;
    int weight;
};

bool compare(Brick a, Brick b){
    return a.weight < b.weight;
}

int main(void){
    int N;
    int maximum = 0;
    int dp[101] = {0, };
    Brick brick[101] = {0, };
    vector<int> result;

    cin >> N;

    for(int i = 1; i <= N; i++){
        brick[i].number = i;
        cin >> brick[i].area >> brick[i].height >> brick[i].weight;
    }

    sort(brick+1, brick + N + 1, compare);


    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= i; j++){
            if(brick[i].area > brick[j].area){
                dp[i] = max(dp[i], dp[j] + brick[i].height);
                maximum = max(maximum, dp[i]);
            }
        }
    }
    
    int index = N;

    while(index != 0){
        if(dp[index] == maximum){
            result.push_back(brick[index].number);
            maximum -= brick[index].height;
        }
        index--;
    }

    cout << result.size() << '\n';

    for(int i = result.size() - 1; i >= 0; i--){
        cout << result[i] << '\n';
    }
}