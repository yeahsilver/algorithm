#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void combination(string order, vector<char> comb, int r, int index, int depth, unordered_map<string, int>& umap) {
    if (r == 0) {
        string key = "";
        for(int i = 0; i < comb.size(); i++) {
            key += comb[i];
        }

        sort(key.begin(), key.end());
        umap[key]++;
        
    } else if (depth == order.size()) {
        return ;

    } else {
        comb[index] = order[depth];
        combination(order, comb, r-1, index+1, depth+1, umap);

        combination(order, comb, r, index, depth+1, umap);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int num: course) {
        unordered_map<string, int> umap;

        for(string order: orders) {
            vector<char> comb(num);
        
            combination(order, comb, num, 0, 0, umap);
        }

        int maxNum = 0;
        vector<string> maxValue;
        
        for(auto& i: umap) {
            if(i.second > 1) {
                if(maxNum< i.second) {

                    maxValue.clear();
                    maxValue.push_back(i.first);
                    maxNum = i.second;
                
                } else if(maxNum == i.second) {
                    maxValue.push_back(i.first);
                }
            }
        }

        for(string value: maxValue) {
            answer.push_back(value);
        }
    }

    sort(answer.begin(), answer.end());
    
    return answer;
}

int main(void) {
    vector<string> orders;
    orders.push_back("ABCDE");
    orders.push_back("AB");
    orders.push_back("CD");
    orders.push_back("ADE");
    orders.push_back("XYZ");
    orders.push_back("XYZ");
    orders.push_back("ACD");

    vector<int> course;
    course.push_back(2);
    course.push_back(3);
    course.push_back(5);

    vector<string> result = solution(orders, course);

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
}