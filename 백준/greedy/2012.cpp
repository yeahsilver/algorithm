#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    long long N;
    vector<long long> predictedRank;
    cin >> N;

    for(long long i = 0; i < N; i++){
        long long input;
        cin >> input;
        predictedRank.push_back(input);
    }

    sort(predictedRank.begin(), predictedRank.end());

    long long totalComplaint = 0;

    for(long long i = 1; i <= N; i++){
        totalComplaint += abs(predictedRank[i-1]- i);
    }

    cout << totalComplaint;
}