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
    
    int helper(TreeNode* root, int max){
        if(root == NULL){
            return 0;
        }
        
        if(max <= root->val){
            max = root->val;
            return 1 + helper(root->left,max) + helper(root->right, max);
            
        } 
        
        return helper(root->left,max) + helper(root->right,max);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans = helper(root,root->val);
        return ans;
    }
};