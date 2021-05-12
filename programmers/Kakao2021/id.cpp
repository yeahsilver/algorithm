// 아이디 길이: 3자 이상 15자 이하
// 아이디: 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표
// .는 처음과 끝에 사용할 수 없으며, 연속으로 사용 불가


#include <string>
#include <vector>

using namespace std;

#define for(i, start, end) for(int i = start; i < end; i++)

string solution(string new_id) {
    string answer = "";
    
    // 1. 대문자 -> 소문자로 치환 (ASCII코드 사용)
    for(i, 0, new_id.length()) {
        new_id[i] = tolower(new_id[i]);
    }
    
    // 2. 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표 제외 모든 문자 제거 (if문으로 거르기)
    for(i, 0, new_id.length()) {
        if ((new_id[i] >= 'a' &&  new_id[i] <= 'z') 
            || (new_id[i] >= '0' &&  new_id[i] <= '9') 
            || new_id[i] == '_' || new_id[i] == '-' || new_id[i] == '.') {
            answer.push_back(new_id[i]);
        } else {
            continue;
        }
    }
    
    // 3. 마침표 2번 연속 사용 -> 마침표 한개 빼기
    string temp = "";
    for(i, 0, answer.length()) { 
        
       if(answer[i] == '.') {
           temp.push_back('.');
           while(i < answer.length() && answer[i] == '.') {
               i++;
           } i--;
       } else {
           temp.push_back(answer[i]);
       }
    }
    
    answer = temp;
    
    // 4. 마침표 처음이나 끝에 존재한다면 빼기 (new_id[0] == '.' && new_id[new_id.length()-1] == '.')
    if(answer[0] == '.') {
        answer = answer.substr(1);
    }
    
    if(answer[answer.length()-1] == '.') {
        answer = answer.substr(0, answer.length()-1);
    }
    
    // 5. new_id가 빈문자열이면 "a" 대입 (if new_id.length() == 0)
    if(answer.empty()) {
        answer = "a";
    }
    
    // 6. 16자 이상이면 뒤에 문자 없애기 (if new_id.length() > 16 new_id 복사해서 대입. 만약 제거 후 마지막이 .이면 제거)
    
    if(answer.length() > 15) {
        answer = answer.substr(0, 15);
        
        if(answer[answer.length()-1] == '.') {
            answer = answer.substr(0, answer.length()-1);
        }
    }
    // 7. new_id가 2자 이하라면, new_id의 마지막 문자를 new_id가 3이 될 때 까지 반복해서 붙임. 
    // (if new_id.length() <= 2 ==> string+=new_id[new_id.length()])
    
    
    while(answer.length() <= 2) {
        answer += answer[answer.length()-1];
    }
    
    return answer;
}