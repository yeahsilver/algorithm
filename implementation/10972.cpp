#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;

    vector<int> v;
    vector<int> prev;

    for(int i = 1; i <= N; i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }   

   if(next_permutation(v.begin(), v.end()) == true) {
       for(int i = 0; i < N; i++) {
           cout << v[i] << ' ';
       }
   } else {
       cout << -1 << '\n';
   }

   return 0;
}