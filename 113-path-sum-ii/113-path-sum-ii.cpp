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
    vector<vector<int>> res;
    vector<int> v;
    
    void dfs(TreeNode *node, int targetSum, int pathSum){
        if(node==NULL){
            return;
        }
        pathSum += node->val;
        v.push_back(node->val);
        if(pathSum==targetSum){
            if(node->left==NULL && node->right==NULL){
                res.push_back(v);
            }
        }
        if(node->left){
            dfs(node->left,targetSum,pathSum);
        }
        if(node->right){
            dfs(node->right,targetSum,pathSum);
        }
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum,0);
        return res;
    }
};