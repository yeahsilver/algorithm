#include <iostream>
#include <vector>

using namespace std;

void heap(vector<int> numbers, int num) {
    for(int i = 1; i < num; i++) {
        int child = i; // 자식 노드 지정
        while(child > 0) { // 루트로 도달할 때 까지
            int root = (child-1)/2; //  자식 노드의 부모 노드의 인덱스 정의
            if(numbers[root] < numbers[child]) { // 자식이 루트보다 크면 자리 이동
                int temp = numbers[child]; 
                numbers[root] = numbers[child];
                numbers[child] = temp;
            }
            child = root; // 루트노드를 자식 노드로 변경 후 계속해서 탐색
        }
    }
}

int main(void) {
    int N;
    cin >> N;

    vector<int> numbers(N);

    for(int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    heap(numbers, N);

    for(int i = N-1; i >=0; i--) {
        int temp = numbers[i];
        numbers[i] = numbers[0];
        numbers[0] = temp;

        heap(numbers, i);
    }

    for(int i = 0; i < N; i++) {
        cout << numbers[i] << '\n';
    }
}