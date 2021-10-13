#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int num;
    vector<int> vector_sorted;

    cin >> num;

    for(int i = 0; i < num; i++){
        int input;
        cin >> input;

        vector_sorted.push_back(input);
    }
    
    sort(vector_sorted.begin(), vector_sorted.end());

    for(int i= 0; i < num; i++){
        cout<<vector_sorted[i]<<'\n';
    }
}
