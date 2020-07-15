#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n, condition;
    int max_num = 0;
    vector<int> vector;

    cin >> n >> condition;
    for(int i = 0; i < n; i++){
        int input;

        cin >> input;
        vector.push_back(input);
    }

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++ ){
            for(int k = j; k < n; k++){
                if(i == j || i == k || j == k) continue;
                int temp = vector[i] + vector[j] + vector[k];
                if(temp <= condition && max_num < temp){
                    max_num = temp;
                }
            }
        }
    }
    cout << max_num << '\n';
}