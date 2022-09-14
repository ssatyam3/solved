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
    int count = 0;
    
    void preorder(TreeNode* node, int path) {
        if (node != NULL) {
            // compute occurences of each digit 
            // in the corresponding register
            path = path ^ (1 << node->val);
            // if it's a leaf check if the path is pseudo-palindromic
            if (node->left == NULL && node->right == NULL) {
                // check if at most one digit has an odd frequency
                if ((path & (path - 1)) == 0) {
                    ++count;
                }
            }
            preorder(node->left, path);
            preorder(node->right, path) ;
        }
    }    
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root, 0);
        return count;
    }
};