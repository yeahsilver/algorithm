#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

int main(void) {

   int n = 8, k = 2;

    vector<string> commands;

    vector<int> erase_number;

    commands.push_back("D 2");
    commands.push_back("C");
    commands.push_back("U 3");
    commands.push_back("C");
    commands.push_back("D 4");
    commands.push_back("C");
    commands.push_back("U 2");
    commands.push_back("Z");
    commands.push_back("Z");

    list<bool> chart;

    for(int i = 0; i < n; i++) {
       chart.push_back(true);
    }

    auto iter = chart.begin();

    for(int i = 0; i < k; i++) {
        iter++;
    }

    for(int i = 0; i < commands.size(); i++) {
       
        if (commands[i][0] == 'U') {

            for(int j = 0; j < commands[i][2] - '0'; j++) {
                iter--;
            }

        } else if (commands[i][0] == 'D') {
            for(int j = 0; j < commands[i][2] -'0'; j++) {
                iter++;
            }
        } else if (commands[i][0] == 'C') {
            
            erase_number.push_back(distance(chart.begin(), iter));

            chart.erase(iter);
             
            if(iter == chart.end()) {
               iter--;
            } else {
                iter++;
            }

        } else if(commands[i][0] =='Z'){
            int value = erase_number.back();
            erase_number.pop_back();
        }
    }

    string str = "";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < erase_number.size(); j++) {
            if(i == erase_number[j]) {
                str += 'X';
            } else {
                str += 'O';
            }
        }
    }

    cout << str << '\n';
}