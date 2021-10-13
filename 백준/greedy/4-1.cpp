#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using namespace std;

int main(void){
    int n;
    cin >> n;

    vector<int> v;

    v.reserve(n);

    for(int i = 0; i < n; i++) {
        int value;
        cin >> value;

        v.push_back(value);
    }

    sort(v.begin(), v.end());

    int result = 0;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        cnt+=1;

        if(cnt >= v[i]) {
            result+=1;
            cnt = 0;
        }
    }

    cout << result << '\n';
}