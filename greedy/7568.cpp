#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct People {
    int weight;
    int height;
};

int main(void) {
    int N;
    cin >> N;

    People* people = new People[N+1];

    for(int i = 0; i < N; i++) {
        int weight, height;
        cin >> weight >> height;
        people[i].weight = weight;
        people[i].height = height;
    }

    int* rank = new int[N+1];
    
    for(int i = 0; i < N+1; i++) {
        rank[i] = 0;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            if(people[i].weight < people[j].weight && people[i].height <  people[j].height) {
                rank[i]++;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << rank[i]+1 << '\n';
    }
}