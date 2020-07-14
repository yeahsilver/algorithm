#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100

int main(void){
    int r, c, k, n;
    cin >> r >> c >> k;
    vector<pair<int, int> > v;
    int countNum[MAX]= {0,};
    int A[MAX][MAX] = {0, };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j <3; j++){
            cin >> n;
            A[i][j] = n;
        }
    }
    int sec = 0, row = 3, column = 3;
    while(1){
        vector<int> Size;
        if(A[r][c] = k)
            break;
        else if(A[r][c] > 100) {
            sec = -1;
            break;
        }
        else if(row >= column){
            for(int i = 0; i <row; i++){
                vector<pair<int, int> > v;
                memset(countNum, 0, sizeof(countNum));
                for(int j = 0; j < column; j++){
                    countNum[A[i][j]]++;
                }
                for(int j = 0; j <MAX; j++){
                    if(countNum[j] != 0)
                        v.push_back(make_pair(countNum[j], j));
                }
                sort(v.begin(), v.end());
                for(int j = 0; j <column; j++){
                    A[i][j] = 0;
                }
                int index = 0;
                for(int j = 0; j <v.size(); j++){
                    A[index++][i] = v[j].second;
                    A[index++][i] = v[j].first;
                }
                index--;
                Size.push_back(index);
                column = Size.back();
            }
        } else {
            for(int i = 0; i <row; i++){
                vector<pair<int, int> > v;
                memset(countNum, 0, sizeof(countNum));
                for(int j = 0; j < column; j++){
                    countNum[A[i][j]]++;
                }
                for(int j = 0; j <MAX; j++){
                    if(countNum[j] != 0)
                        v.push_back(make_pair(countNum[j], j));
                }
                sort(v.begin(), v.end());
                for(int j = 0; j <row; j++){
                    A[i][j] = 0;
                }
                int index = 0;
                for(int j = 0; j <v.size(); j++){
                    A[index++][i] = v[j].second;
                    A[index++][i] = v[j].first;
                }
                index--;
                Size.push_back(index);
                column = Size.back();
            }
        }
        sort(Size.begin(), Size.end());
        sec++;
    }
    cout<<

}