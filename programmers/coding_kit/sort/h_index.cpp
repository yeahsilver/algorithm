#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    예시) 5편 중에 3번 이상 인용된 논문이 3편 이상이고, 나머지 논문(2편)이 3번 이하의 논문에 인용되었다면,
        3의 최댓값이 과학자의 H-index
    문제: 인용 된 논문을 count 해서 최대 h-index를 찾아라 

    예: 3 0 6 1 5
    개수: 5개

    1. h == 0 => 5편 중 0번 이상 인용된 논문이 5편 (x)
    2. h == 1 => 5편 중 1번 이상 인용된 논문이 4편 (x)
    3. h == 2 => 5편 중 2번 이상 인용된 논문이 3편 (x)
    4. h == 3 -> 5편 중 3번 이상 인용된 논문이 3편 (O)

    결론)
    sort로 정렬 => 6 5 3 1 0
    for문을 돌려서 h번 이상 인용된 논문을 체크

    citation[i] 인용된 횟수
    6           1
    5           2
    3           3
    1           4 ==> break

*/

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end(), greater<int>());

    if(citations[0] == 0) return 0;

    while(true) {
        if(citations[answer] <= answer) {
            break;
        } 

        answer++;
    }

    return answer;
}

int main(void) {
    vector<int> citations;
    citations.push_back(3);
    citations.push_back(0);
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(5);

    cout << solution(citations);
}