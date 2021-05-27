#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

#define MAX 16

/*
    1. bitset을 사용하여 array의 값을 이진수로 만들어주기.
       이 때 크기는 n만큼
    2. for문을 돌려 bitset1에서 1이면 비밀 지도 배열에 1 넣기
    3. 이후 for문을 돌려 bitset2을 비교하는데, bitset2에서 1일 떄 비밀 지도 배열이 1 삽입 (이때 이미 1이 들어가있다면 continue)
    4. 배열에 1이 들어가는 곳만 #으로 출력. 아니면 공백.
*/

string encrpytion(int n, int index, vector<int> arr1, vector<int> arr2) {
    string s1 = bitset<MAX>(arr1[index]).to_string();
    string s2 = bitset<MAX> (arr2[index]).to_string();

    string result = "";

    for(int j = MAX-n; j < s1.size(); j++) {
        
        if(s1[j] == '0' && s2[j] == '0') {
            result.push_back(' ');

        } else if(s1[j] == '1' || s2[j] == '1') {
            result.push_back('#');
        }
    }

    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    int secret_map[MAX][MAX] = {0, };
    
    for(int i = 0; i < n; i++) {
        answer.push_back(encrpytion(n, i, arr1, arr2));
    }

    return answer;
}

int main(void) {
    int n = 5;
    
    vector<int> arr1, arr2;

    arr1.push_back(9);
    arr1.push_back(20);
    arr1.push_back(28);
    arr1.push_back(18);
    arr1.push_back(11);

    arr2.push_back(30);
    arr2.push_back(1);
    arr2.push_back(21);
    arr2.push_back(17);
    arr2.push_back(28);

    vector<string> answer = solution(n, arr1, arr2);

    for(int i = 0; i < answer.size(); i++) {
        for(int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << '\t';
        }

        cout << '\n';
    }
}