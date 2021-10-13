#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    cin.tie(NULL), cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int crainNum;
    cin >> crainNum;

    vector<int> crainWeight;
    for(int i = 0; i < crainNum; i++){
        int input;
        cin >> input;
        crainWeight.push_back(input);
    }

    int boxNum;
    cin >> boxNum;

    vector<int> boxWeight;
    for(int i = 0; i < boxNum; i++){
        int input;
        cin >> input;
        boxWeight.push_back(input);
    }

    sort(crainWeight.begin(), crainWeight.end(),greater<int>());
    sort(boxWeight.begin(), boxWeight.end(), greater<int>());

    if(crainWeight[0] < boxWeight[0]){
        cout << "-1\n";
        return 0;
    }

    int result = 0;

    while(!boxWeight.empty()){
        result++;
        for(int i = 0; i < crainWeight.size(); i++){
            for(int j = 0; j < boxWeight.size(); j++){
                if(crainWeight[i] >= boxWeight[j]){
                    boxWeight.erase(boxWeight.begin() + j);
                    break;
                }
            }
        }
    }
    cout << result;
    return 0;
}