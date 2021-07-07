#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthSmallest(vector<vector<int> >& matrix, int k) {
    vector<int> oneDimensionMatrix;
        
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            oneDimensionMatrix.push_back(matrix[i][j]);
        }
    }
        
    sort(oneDimensionMatrix.begin(), oneDimensionMatrix.end());
        
    return oneDimensionMatrix.at(k-1);
}

int main(void) {
    vector<vector<int> > matrix;
    
    vector<int> num;
    num.push_back(-5);
    
    matrix.push_back(num);
    
    int k = 1;
    
    cout << kthSmallest(matrix, k) << '\n';
}