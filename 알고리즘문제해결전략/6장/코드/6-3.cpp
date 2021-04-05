#include <iostream>
#include <string>

#define for(i, n) for(int i = 0; i < n; i++)

using namespace std;

string board[5];

int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

bool hasWord(string word, int x, int y) {
    if(x < 0 || x >= 5 || y < 0 || y >= 5 ) {
        return false;
    }

    if(board[x][y] != word[0]) {
        return false;
    }

    if(word.size() == 1) {
        return true;
    }

    for(i, 8) {
        int nX = x + dx[i];
        int nY = y + dy[i];

        if(hasWord(word.substr(1), nX, nY)) {
            return true;
        }
    }
    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_case;
    cin >> test_case;

    while(test_case--) {
         for(i, 5) {
            for(j, 5) {
                cin >> board[i][j];
            }
        }

        int n;
        cin >> n;

        while(n--) {
            string word;
            cin >> word;

            bool flag = false;

            for(i, 5) {
                for(j, 5) {
                    if(board[i][j] == word[0]) {
                        flag = hasWord(word, i, j);
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }

            if(flag) {
                cout << word << ' ' << "YES\n";
            } else {
                cout << word << ' ' << "NO\n";
            }
        }
    } 
}