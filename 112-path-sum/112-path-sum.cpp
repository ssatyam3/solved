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
    int sum=0;
    bool helper(TreeNode *root, int target){
        if(root==nullptr)return false;
        sum+=root->val;
        if(sum==target  && root->left==nullptr && root->right==nullptr)return true;
        if( helper( root->left,target) ||helper(root->right,target))
            return true;
        sum-=root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int target) {
        return helper(root,target);
    }
};