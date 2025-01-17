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
    void solve(TreeNode* root, int val){

        if(root == nullptr)return;
        
        if(val>root->val) {

            if(root->right != nullptr) solve(root->right, val);
            else {
                TreeNode* node = new TreeNode(val);
                root->right = node;
                return;
            }

        }
        else if(val<root->val){

            if(root->left != nullptr) solve(root->left, val);
            else {
                TreeNode* node = new TreeNode(val);
                root->left = node;
                return;
            }

        } 

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root==nullptr){
            TreeNode* node = new TreeNode(val);
            root = node;
        }
        else solve(root, val);
        return root;
        
    }
};