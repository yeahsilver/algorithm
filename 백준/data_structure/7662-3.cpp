#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {
    int testCase;
    cin >> testCase;

    while(testCase--) {
        int num;
        cin >> num;

        multiset<int> ms;

        for(int i = 0; i < num; i++) {
            char type;
            int number;

            cin >> type >> number;

            if(type == 'I') {
                ms.insert(number);

            } else if(type == 'D') {
                if(number == 1) {
                    if(!ms.empty()) {
                        auto iter = ms.rbegin();
                        auto value = ms.find(*iter);
                        
                        ms.erase(value);
                    }

                } else if(number == -1) {
                    if(!ms.empty()) {
                        auto iter = ms.begin();
                        auto value = ms.find(*iter);
                        ms.erase(value);
                    }
                }
            }
        }

        if(ms.empty()) {
            cout << "EMPTY\n";
        } else {
            auto maxIt = ms.rbegin();
            auto minIt = ms.begin();

            cout << *maxIt << ' ' << *minIt << '\n';
        }
    }
}