#include <iostream>
#include <cstring>

using namespace std;

#define MAX 101

int main(void){
    int test_case;
    cin >> test_case;

    while(test_case--){
        int num;
        int cnt = 0;
        int map[MAX][MAX] = {0,};

        cin >> num;

        while(num--){
            int x, y;
            cin >> x >> y;

            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    map[x + i][y + j] = 1;
                }
            }
        }

        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                if(map[i][j] == 1){
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}