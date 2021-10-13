#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAX 11

using namespace std;

bool isChecked[MAX] = {false, };
char direction[MAX];
int N;
int arr[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

vector<string> answer;
vector<int> v;

bool isPossible () {
    for(int i = 0; i < N; i++) {
        if(direction[i] == '<') {
            if(v[i] > v[i+1]) {
                return false;
            }
        } else if (direction[i] == '>' ) {
            if(v[i] < v[i+1]) {
                return false;
            }
        }
    }
    return true;
}

void DFS(int cnt) {
    if(cnt == N + 1) {
        if(isPossible()){
            string temp = "";

            for(int i = 0; i < v.size(); i++) {
                temp += to_string(v[i]);
            }
            answer.push_back(temp);
        }
        return;
    }

    for(int i = 0; i <= 9; i++) {
        if (!isChecked[i]) {
            v.push_back(i);
            isChecked[i] = true;
            DFS(cnt+1);
            v.pop_back();
        } 
    }
   
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;

    for(int i = 0; i < N; i++) {
        char arrow;
        cin >> arrow;
        direction[i] = arrow;
    }

    DFS(0);

    cout << answer[answer.size()-1] << '\n';
    cout << answer[0] << '\n';
}   
