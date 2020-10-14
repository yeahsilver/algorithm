#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10001

int level = 1;
int totalDepth = 0;

int minArr[MAX];
int maxArr[MAX];

struct Node{
    Node* left;
    Node* right;
    int value;
    int parent;
    int depth;
    int column;
};


void inorder(Node* node, int depth){
    node->depth = depth;
    if(node->left){
        inorder(node->left, depth+1);
    }
    node->column = level++;

    minArr[node->depth] = min(node->column, minArr[node->depth]);
    maxArr[node->depth] = max(node->column, maxArr[node->depth]);

    if(node->right){
        inorder(node->right, depth+1);
    }
}

int main(void){
    int N, root;
    cin >> N;

    Node* tree = (Node*) malloc(sizeof(Node) * (N+1));

    for(int i = 1; i <= N; i++){
        minArr[i] = __INT_MAX__;
    }

    for(int i = 0; i < N; i++){
        int value, left, right;
        cin >> value >> left >> right;

        tree[value].value = value;

        if(left != -1){
            tree[value].left = &tree[left];
        } else {
            tree[value].left = NULL;
        }

        tree[left].parent = value;

        if(right != -1){
            tree[value].right = &tree[right];
        } else {
            tree[value].right = NULL;
        }

        tree[right].parent = value;
    }

    for(int i = 1; i <= N; i++){
        if(tree[i].parent > 0 && tree[i].parent <= N){
            continue;
        }
        root = i;
    }

    inorder(&tree[root], 1);

    int maxDepth = maxArr[1] - maxArr[1] + 1;
    int maxLevel = 1;

    for(int i = 2; i <= N; i++){
        int temp = maxArr[i] - minArr[i] + 1;
        if(temp > maxDepth){
            maxDepth = temp;
            maxLevel = i;
        }

    }
    cout << maxLevel << ' ' << maxDepth << '\n';
}