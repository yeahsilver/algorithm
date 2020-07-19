#include <iostream>
#include <queue>

using namespace std;

int main(void){
    int test_case;
    
    cin >> test_case;

    for(int i = 0; i < test_case; i++){
        int n, m;
        int cnt = 0;

        priority_queue<int> pq;
        queue<pair<int, int> > q;

        cin >> n >> m;
        
        for(int j = 0; j < n; j++){
            int input;
            
            cin >> input;
            q.push(make_pair(j, input));
            pq.push(input);
        }

        while(!q.empty()){
            int index = q.front().first;
            int importance = q.front().second;

            q.pop();

            if(importance == pq.top()){
                pq.pop();
                cnt++;
                if(index == m){
                    cout<<cnt<<'\n';
                    break;
                }
            } else {
                q.push(make_pair(index, importance));
            }
        }
    }
}