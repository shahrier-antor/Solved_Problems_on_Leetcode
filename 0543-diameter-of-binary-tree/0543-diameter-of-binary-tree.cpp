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
    pair<int,int>solve(TreeNode* root, int diameter){
        if(root==nullptr)return {0,diameter};
        auto left = solve(root->left,diameter);
        auto right = solve(root->right,diameter);
        diameter = max (left.first+right.first, diameter);
        return {max(left.first,right.first)+1,diameter};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        auto answer = solve(root,0);
        return answer.second;
    }
};