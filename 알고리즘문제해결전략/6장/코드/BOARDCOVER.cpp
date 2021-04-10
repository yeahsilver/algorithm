#include <iostream>
#include <cstring>

#define MAX 20
#define for(i, start, end) for (int i = start; i < end; i++)

using namespace std;

int board[MAX][MAX] =  {0, };

int height, width;

int shape[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}}, 
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

bool set(int x, int y, int type, int delta) {
    bool ok = true;

    for(i, 0, 3) {
        int nX = x + shape[type][i][0];
        int nY = y + shape[type][i][1];

        if(nX < 0 || nY < 0 || nX >= height ||  nY >= width) {
            ok = false;
        } else if ((board[nX][nY]+=delta) > 1) {
            ok = false;
        }
    }

    return ok;
}

int cover() {
    int x = -1;
    int y = -1;

    for(i, 0, height) {
        for(j, 0, width) {
            if(board[i][j] == 0) {
                x = i;
                y = j;
                break;
            }
        }
        if(x != -1) {
            break;
        }
    }

    if(x == -1) {
        return 1;
    }

    int count = 0;

    for(type, 0, 4) {
        if(set(x, y, type, 1)) {
            count += cover();
        }

        set(x, y, type, -1);
    }

    return count;
}

int main(void) {
    int test_case;
    cin >> test_case;

    while(test_case--) {
        memset(board, 0, sizeof(board));

        cin >> height >> width;

        for(i, 0, height) {
            for(j, 0, width) {
                char value;
                cin >> value;

                value == '#' ? board[i][j] = 1 : board[i][j] = 0;
            }
        }
        cout << cover() << '\n';
    }
}