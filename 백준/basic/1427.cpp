#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    string s;
    vector<int> vector_sorted;

    cin >> s;

    for(int i = 0; i < s.length(); i++){
        int input = s[i] -'0';
        vector_sorted.push_back(input);
    }

    sort(vector_sorted.begin(), vector_sorted.end());

    for(int i = s.length()-1; i >= 0; i--){
        cout << vector_sorted[i];
    }
}