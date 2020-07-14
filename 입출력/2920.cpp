#include <iostream>
#include <vector>

using namespace std;

int main(void){
    vector<int> vector;
    bool ascending = true;
    bool descending = true;
    
    for(int i = 0; i < 8; i++){
        int input;
        cin >> input;
        vector.push_back(input);
    }

    for(int i = 1; i < 8; i++){
        if(vector[i] < vector[i-1]){
            ascending = false;
        }
        if(vector[i] > vector[i-1]){
            descending = false;
        }
    }

    if(ascending){
        cout<<"ascending\n";
    } else if(descending){
        cout<<"descending\n";
    } else {
        cout<<"mixed\n";
    }

}