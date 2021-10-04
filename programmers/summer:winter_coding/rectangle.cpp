#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {1, 1, 0, 1};
int dy[4] = {1, 0, 1, 0};

long long solution(int w, int h) {

    long long answer = 0;
    vector<pair<long long, long long> > v;

    v.push_back(make_pair(0, 0));

    while(1) {
        if(v.back().first >= h || v.back().second >= w) {
            break;
        }

        for(int i = 0; i < 4; i++) {
            if(v.back().first > h || v.back().second > w) {
                break;
            }

            long long cx = v.back().first;
            long long cy = v.back().second;

            v.push_back(make_pair(cx+dx[i], cy+dy[i]));
            answer++;

        }
    }
    
    return (w * h) - (answer);
}

int main(void) {
    int W = 8;
    int H = 12;

    cout << solution(W, H) << '\n';
}