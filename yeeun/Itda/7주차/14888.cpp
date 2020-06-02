#include <iostream>
#include <algorithm>
using namespace std;

const int MAX =  1000000001;

int N;
int op[4] = {0,};
int a[12] = {0,};
int maxResult = -MAX, minResult = MAX;

void DFS(int plus, int minus, int mult, int div, int count, int sum){
    if(count == N){
        minResult = min(minResult, sum);
        maxResult = max(maxResult ,sum);
    }

    if(plus > 0){
        DFS(plus-1, minus, mult, div, count + 1, sum + a[count]);
    }
     if(minus > 0){
        DFS(plus, minus-1, mult, div, count + 1, sum - a[count]);
    }
     if(mult > 0){
        DFS(plus, minus, mult-1, div, count + 1, sum * a[count]);
    }
     if(div > 0){
        DFS(plus, minus, mult, div-1, count + 1, sum / a[count]);
    }
}

int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }

    DFS(op[0],op[1],op[2],op[3],1,a[0]);

    cout << maxResult <<endl;
    cout << minResult <<endl;

}