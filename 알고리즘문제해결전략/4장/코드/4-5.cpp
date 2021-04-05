// 미완성

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MAX 51

int friend_number, food_number;

vector<int> eat_food_list[MAX];
vector<int> people_can_eat[MAX];


// TODO
// 1. recursive 함수로 모든 경우의 수를 계산한다.
// 2. 친구들이 먹을 수 있는 음식을 매칭 하여 모두 먹을 수 있으면 cnt 변수에 저장한다. 이 때 min_cnt > cnt이면 min_cnt = cnt;를 넣어준다

void edible(int food_chosen, vector<int> food_list){
    // 음식의 개수보다 선택된 음식의 번호가 같거나 더 클 때는 존재하지 않는 것이기에 재귀를 끝내야함.

    if (food_chosen == 0) {
         edible(food_chosen, food_list);

        food_list.push_back(food_chosen);
        edible(food_chosen, food_list);
    }
    
    if(food_number <= food_chosen) {

       for(int i = 0; i < food_list.size(); i++) {
           cout << food_list[i] << '\t';
       }

        cout << '\n';

        vector<bool> isEating(friend_number, false);

        for(int i = 0; i < friend_number; i++) {
            for(int j = 0; j < eat_food_list[i].size(); j++) {
                for(int k = 0; k < food_list.size(); k++) {
                    if(eat_food_list[i][j] == food_list[k]) {
                        isEating[i] = true;
                    }
                }
            }
        }

        

        for(int i = 0; i < isEating.size(); i++) {
            cout << isEating[i] << '\t';
        }
        cout << '\n';


        return;
    }


    food_chosen++;
    
    edible(food_chosen, food_list);

    food_list.push_back(food_chosen);
    edible(food_chosen, food_list);
    

}

int main(void){
    int test_case;
    cin >> test_case;

    while(test_case--) {
        
        cin >> friend_number >> food_number;

        map<string, int> info;

        for(int i = 0; i < friend_number; i++) {
            string name;
            cin >> name;

            info[name] = i;
        }
        
        for(int i = 0; i < food_number; i++) {
            int can_eat_people;
            cin >> can_eat_people;

            for(int j = 0; j < can_eat_people; j++) {
                string name;
                cin >> name;

                int inserted_data = info[name];

                eat_food_list[i].push_back(inserted_data);

                people_can_eat[inserted_data].push_back(i);
            }
        }

        for(int i = 0; i < food_number; i++) {
            cout << "food number " << i << ": \t";
            for(int j = 0; j < eat_food_list[i].size(); j++) {
               cout << eat_food_list[i][j] << '\t';
            } 
            cout << '\n';
        }

        vector<int> food_list;

        edible(0, food_list);
    }
}