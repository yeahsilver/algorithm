#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1001

int main(void){
    int LCS[MAX][MAX] = {0,};
    string a, b;
    cin >> a >> b;

    for(int i = 1; i <= a.length(); i++){
        for(int j = 1; j <= b.length(); j++){
            if(a[i-1] == b[j-1]){
                LCS[i][j] = LCS[i-1][j-1] + 1;
            } else {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    
    cout << LCS[a.length()][b.length()] << '\n';
}