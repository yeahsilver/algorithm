#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int N,M; // 가로와 세로의 길이
    int n; // 자르는 횟수
    cin>>N>>M>>n;
    vector<int> width;
    vector<int> height;
    vector<int> temp1;
    vector<int> temp2;
  
    for(int i = 0; i <n; i++){
        bool isHeight; // 가로인지 세로인지 구별해주는 역할
        int x;
        cin>>isHeight>>x;
        if(isHeight == 0){
             width.push_back(x);
        } else {
            height.push_back(x);
        }
    }

    width.push_back(M);
    height.push_back(N);

    sort(width.begin(), width.end());
    sort(height.begin(), height.end());

    for(int i = 0 ; i<width.size(); i++){
        if(i == 0){ // 첫번째로 자를 때
            temp1.push_back(width[i]);
        } else {
            temp1.push_back(width[i]-width[i-1]);
        }
    }

    for(int i = 0 ; i<height.size(); i++){
        if(i == 0){ // 첫번째로 자를 때
            temp2.push_back(height[i]);
        } else {
            temp2.push_back(height[i]-height[i-1]);
        }
    }

    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());

    cout<<temp1[temp1.size()-1]*temp2[temp2.size()-1];
}