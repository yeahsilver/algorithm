#include <iostream>
#include <queue>

using namespace std;

int main(void){
    int N, k;
    cin >> N >> k;

    queue<int> q;

    for(int i =0; i < N; i++){
        q.push(i+1);
    }

    cout<<"<";
    for(int i = 0; i < N-1; i++){
        
        for(int j = 0; j < k-1; j++){
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<", ";
        q.pop();
    }
    cout<<q.front()<<">";

}