#include <iostream>
#include <string>

using namespace std;

int main(void){
    string a, b;
    getline(cin, a);
    getline(cin, b);

    if(a.length() < b.length()){
        cout << 0 << '\n';
    } else {
        int total = 0;
        
        for(int i = 0; i < a.length(); i++){
            bool isCorrect = true;
            for(int j = 0; j < b.length(); j++){
                if(a[i+j] == b[j]){
                    isCorrect = true;
                } else {
                    isCorrect = false;
                    break;
                }
            }
            if (isCorrect == true){
                total++;
                i += b.size()-1;
            }
        }
        cout << total << '\n';
    }
}