#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 21

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    bool isExist[MAX] = {false, };

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if(command == "add") {
            int value;
            cin >> value;
            isExist[value] = true;

        } else if (command == "remove") {
            int value;
            cin >> value;
            isExist[value] = false;

        } else if (command == "check") {
            int value;
            cin >> value;
            isExist[value] ? cout << 1 << '\n' : cout << 0 << '\n';

        } else if (command == "toggle") {
            int value;
            cin >> value;
            isExist[value] ? isExist[value] = false : isExist[value] = true;

        } else if(command == "all") {
            for(int i = 0; i < MAX; i++) {
                isExist[i] = true;
            }
        } else if (command == "empty") {
            memset(isExist, false, sizeof(isExist));
        }
    }

    return 0;
}