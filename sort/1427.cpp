
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    string str;
    vector<int> vector_sorted;

    cin >> str;

    for(int i = 0; i < str.length(); i++){
        int input= str[i] - '0';
        vector_sorted.push_back(input);
    }

    sort(vector_sorted.begin(), vector_sorted.end());

    for(int i = str.length()-1; i >= 0; i—){
        cout<<vector_sorted[i];
    }
}
