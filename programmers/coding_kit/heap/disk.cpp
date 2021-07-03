#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    priority_queue<vector<int>, vector<int>, greater<int> > pq;

    sort(jobs.begin(), jobs.end());

    for(int i = 0; i < jobs.size(); i++) {
       cout << jobs. << '\t' << jobs[i][1] << '\n';
    }
}

int main(void) {
    vector<vector<int>> jobs;
    jobs[0].push_back(3);
    jobs[1].push_back(9);
    jobs[2].push_back(9);

    cout << solution(jobs);
}