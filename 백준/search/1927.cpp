#include <iostream>
#include <queue>

using namespace std;

int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int> > queue;

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;

        if(input == 0){
            if(queue.size()){
                cout << queue.top() << '\n';
                queue.pop();
            } else {
                cout << 0 << '\n';
            }
        } else {
            queue.push(input);
        }
    }
}
