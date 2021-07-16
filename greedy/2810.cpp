#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<char> v; 
    
    for(int i = 0; i < n; i++) {
        char value;
        cin >> value;
        v.push_back(value);
    }

    int cnt = 1;

    for(int i = 0; i < v.size(); i++) {
        if(v[i] == 'S') cnt+=1;
        else if(v[i] == 'L') {
            cnt+=1;
            i++;
        }
    }

    if(v.size() < cnt) {
        cout << v.size() << '\n';
    } else {
         cout << cnt << '\n';
    }
   
}