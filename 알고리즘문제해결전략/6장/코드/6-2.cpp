#include <iostream>
#include <vector>

using namespace std;

// TODO
// 1. 재귀를 받음
// 2. vector.size() == n 이면 출력
// 3. 아닐경우 picked의 값이 없으면 0을 시작점으로, 있으면 back()+1를 시작점으로.   
// 4. for문을 돌려 push_back(i) 해준 뒤, recursive(picked) 재귀가 끝나면 vector.pop_back()

int n, m;

void printPicked(vector<int> picked) {

    for(int i = 0; i < picked.size(); i++) {
        cout << picked[i] << '\t';
    }

    cout << '\n';
}

void recursive(vector<int> picked) {
    if (picked.size() == m) {
        printPicked(picked);
        return;
    }

    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for(int i = smallest; i < n; i++) {
        picked.push_back(i);
        recursive(picked);
        picked.pop_back();
    }
}

int main(void) {
    cin >> n >> m;

    vector<int> picked;

    recursive(picked);
}