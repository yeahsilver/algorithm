#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    vector<int> people;

    int total = 0;
    for(int i = 0; i < 9; i++) {
        int value;
        cin >> value;

        people.push_back(value);
        total += value;
    }

    int index1 = 0;
    int index2 = 0;

    for(int i = 0; i < 9; i++) {
       
        for(int j = 0; j < 9; j++) {
            for(int k = j+1; k < 9; k++) {
                int sum = 0;
                sum += people[j] + people[k];

                if(total - sum == 100) {
                    index1 = j;
                    index2 = k;
                    break;
                }
            }
        }
    }
    
    
    for(int i = 0; i < people.size(); i++) {
        if(i == index1 || i == index2) {
            people[i] = 0;
        }
    }

    sort(people.begin(), people.end());

    for(int i = 2; i < people.size(); i++) {
        cout << people[i] << '\n';
    }
}