#include <iostream>
using namespace std;

int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y,x % y);
} 


int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    int arr[101] = {0,};

    for(int i = 0; i <T; i++){
        int N;
        long long sum = 0;;
        cin >> N;
        for(int i = 0; i < N; i ++){
            cin >> arr[i];
        }

        for(int i = 0; i < N; i++){
            for(int j = i+1; j <N; j++){
                
                sum+=gcd(arr[i],arr[j]);
            }
        }
        cout<<sum<<"\n";
        
    }

}