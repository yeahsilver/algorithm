#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > matrixReshape(vector<vector<int> >& mat, int r, int c) {
    vector<int> oneDimensionMatrix;
    vector<vector<int> > result;

    int m = mat.size();
    int n = mat[0].size();

    if(r*c != m*n) {
        return mat;
    }

    for(int i = 0; i < r; i++) {
        vector<int> values;

        for(int j = 0; j < c; j++) {
            int k = c * i + j;
            values.push_back(mat[k/n][k%n]);
        }

        result.push_back(values);
    }

    return result;
}

int main(void) {
    vector<vector<int> > mat;

    vector<int> num1;
    vector<int> num2;
    
    num1.push_back(1);
    num1.push_back(2);

    num2.push_back(3);
    num2.push_back(4);

    mat.push_back(num1);
    mat.push_back(num2);
    
    int r = 4;
    int c = 1;

    vector<vector<int> > result = matrixReshape(mat, r, c);
    
    cout << "[";

    for(int i = 0; i < result.size(); i++) {
        cout << "[";
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << '\t';
        }
        cout << "]";
        cout << '\n';
    }

    cout << "]";
}