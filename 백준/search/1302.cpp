#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main(void){
    int N;
    int cnt = 0;
    int maxCnt = 0;
    vector<string> list;

    cin >> N;

    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        list.push_back(input);
    }

    sort(list.begin(), list.end());

    string tmp = list[0];
    string result;

    for(int i = 0; i < N; i++){
        if(tmp == list[i]){
            cnt++;
        } else {
            if(maxCnt < cnt){
                maxCnt = cnt;
                result = tmp;
            }
            tmp = list[i];
            cnt = 1;
        }
    }
    
    if(cnt > maxCnt){
        result = tmp;
    }

    cout << result << '\n';
    
}