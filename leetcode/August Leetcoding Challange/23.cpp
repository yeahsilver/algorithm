/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> values;
        return isTwoSumAvailable(root, values, k);
    }
    
    bool isTwoSumAvailable(TreeNode* root, unordered_set<int>& values, int k) {
        
        // leaf 노드일 경우
        if(root == nullptr) {
            return false;
        }
        
        // k-root->val 값이 values에 있는 경우 true 반환
        if(values.count(k - root->val) > 0)  {
            return true;
        }
        
        // 둘다 포함이 안된다면 root->val 넣기
        values.insert(root->val);
        
        // 왼쪽 서브트리와 오른쪽 서브트리 비교
        return isTwoSumAvailable(root->left, values, k) || isTwoSumAvailable(root->right, values, k);
    }
};