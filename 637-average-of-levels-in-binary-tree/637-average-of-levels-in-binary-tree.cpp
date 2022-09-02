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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        que.emplace(root);
        while(!que.empty()){
            long sum=0, count=0;
            queue<TreeNode*> tmp;
            while(!que.empty()){
                TreeNode *n = que.front();
                que.pop();
                sum += n->val;
                count++;
                if(n->left != NULL){
                    tmp.emplace(n->left);
                }
                if(n->right != NULL){
                    tmp.emplace(n->right);
                }
            }
            que = tmp;
            res.push_back(sum*1.0/count);
        }
        return res;
    }
};