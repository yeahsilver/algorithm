#include <iostream>

using namespace std;

int main(void){
    int money;
    int cnt = 0;
    cin >> money;

    money = 1000 - money;

    while(1){
        if(money == 0){
            break;
        }
        if(money >= 500){
            money-=500;
            cnt++;
            continue;
        }
        if(money >= 100){
            money-=100;
            cnt++;
            continue;
        }
        if(money >= 50){
            money-=50;
            cnt++;
            continue;
        }
        if(money >= 10){
            money-=10;
            cnt++;
            continue;
        }
        if(money >= 5){
            money-=5;
            cnt++;
            continue;
        }
        if(money>=1){
            money-=1;
            cnt++;
            continue;
        }
    }
    cout << cnt << '\n';
}