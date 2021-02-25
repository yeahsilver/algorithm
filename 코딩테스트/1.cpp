
#include <iostream>
#include <string>

using namespace std;

int main() {
    int cntBomb = 0;
    int cntRazer = 0;
    
    string str;
    cin >> str;
    
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '(') {
            cntBomb++;
        } else if(str[i] == ')') {
            cntRazer++;
        }
    }
    
    if(cntBomb == cntRazer) {
        cout << "YES \n";
    } else {
        cout << "NO\n";
    }
    
    
    return 0;
}