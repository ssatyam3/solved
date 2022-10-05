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
    void helper(TreeNode* node, int val, int depth){
        if(node==NULL)
            return;
        if(depth == 1){
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            TreeNode* newNode1 = new TreeNode(val,left,NULL);
            TreeNode* newNode2 = new TreeNode(val,NULL,right);
            node->left = newNode1;
            node->right = newNode2;
            
            return;
        }
        if(depth==0){
            TreeNode* newNode = new TreeNode(val,node->left, node->right);
            node->right = NULL;
            node->left = newNode;
            int tmp = newNode->val;
            newNode->val = node->val;
            node->val = tmp;
            return;
            
        }
        if(node->left){
            helper(node->left, val, depth-1);
        }
        if(node->right){
            helper(node->right, val, depth-1);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root)
            return root;
        helper(root, val, depth-1);
        return root;
    }
};