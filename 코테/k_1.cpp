#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    string str = "23four5six7";

    string alphabet[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int num = 0;
    string arr;
    string numbers;

    int k = 0;

    while(k != str.size()){
        if(str[k] > 47 && str[k] < 58) { 
            numbers += to_string(num*10 + str[k]-48);
            k++;

        } else {
            for(int i = 0; i < 9; i++) {
                for(int j = 0; j < alphabet[i].size(); j++) {
                   
                    if(alphabet[i][j] == str[k]){
                        arr += str[k];
                        k++;

                        if(arr == alphabet[i]) {
                            arr = "";
                            numbers += to_string(i+1);
                            break;
                        }

                    } else {
                        continue;
                    }
                }
            }
        }
    }

    cout << stoi(numbers)<< '\n';
}