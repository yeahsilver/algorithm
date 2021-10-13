#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    vector<int> vector;
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        vector.push_back(input);
    }

    sort(vector.begin(), vector.end());

    
    cout<<vector[M-1]<<'\n';
}