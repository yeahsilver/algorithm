#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long convertDecToBi(long long num) {
    long long result = 0;
        
    for(long long i = 1; num > 0; i*=10) {
        long long binary = num % 2;
        result +=binary * i;
        num /= 2;
    } 
    
    return result;
}

long long convertBiToDec(long long num) {
    long long result = 0, mul = 1;
    
    while(num > 0) {
        if(num%2) {
            result += mul;
        }
        
        mul *= 2;
        num /= 10;
    }
    
    return result;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    int length = numbers.size();
    
    for(int i = 0; i < numbers.size(); i++) {
        int cnt = __INT_MAX__;
        
        string str = to_string(convertDecToBi(numbers[i]));

        long long num = numbers[i];
        
        string s;
            
        while(cnt >= 2) {
            cnt = 0;
            num++;
            
            s = to_string(convertDecToBi(num));

            if(s.length() > str.length()) {
                str.insert(0, "0");
            } else if(s.length() < str.length()) {
                s.insert(0, "0");
            } 

            for(int i = 0; i < s.length(); i++) {

                if(str[i] == s[i]) {
                    continue;
                } else {
                    cnt++;
                }
            }

            if(cnt <= 2) {
                break;
            }
        }

        long long value = convertBiToDec(stoll(s));

        answer.push_back(value);
    }

    return answer;
}

int main(void) {
    vector<long long> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    solution(numbers);
}