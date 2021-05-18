#include <iostream>
#include <string>
#include <vector>
#include <bitset>

#define MAX 100000

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long i = 0; i < numbers.size(); i++) {
        long long cnt = __INT_MAX__;

        bitset<50> bs1(numbers[i]);
        
        string str = bs1.to_string();

        long long num = numbers[i];
        
        string s;
        
        while(cnt >= 2) {
            cnt = 0;
            num++;
            
            bitset<50> bs2(num);
            
            s = bs2.to_string();

            if(s.length() > str.length()) {
                str.insert(0, "0");
                
            } else if(s.length() < str.length()) {
                s.insert(0, "0");
            } 

            for(long long i = 0; i < s.length(); i++) {

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
        
        bitset<MAX> result(s);
        
        long long value = result.to_ullong();

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