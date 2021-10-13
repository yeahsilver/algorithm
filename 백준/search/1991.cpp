#include <iostream>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    char value;
};

void preorder(Node* node){
    cout << node->value;
    
    if(node->left){
        preorder(node->left);
    }
    if(node->right){
        preorder(node->right);
    }
}

void inorder(Node* node){
    if(node->left){
        inorder(node->left);
    }

    cout << node->value;

    if(node->right){
        inorder(node->right);
    }

}

void postorder(Node* node){
    if(node->left){
        postorder(node->left);
    }
    if(node->right){
        postorder(node->right);
    }

    cout << node->value;
}

int main(void){
    int N;
    cin >> N;

    Node* tree = (Node*) malloc(sizeof(Node) * N);

    for(int i = 0; i < N; i++){
        char value, left, right;
        int index;

        cin >> value >> left >> right;

        index = value - 'A';

        tree[index].value = value;

        if(left == '.'){
            tree[index].left = NULL;
        } else {
            tree[index].left = &tree[left-'A'];
        }

        if(right == '.'){
            tree[index].right = NULL;
        } else {
            tree[index].right = &tree[right-'A'];
        }
    }

    preorder(&tree[0]);
    cout << '\n';

    inorder(&tree[0]);
    cout << '\n';

    postorder(&tree[0]);
    cout << '\n';
}