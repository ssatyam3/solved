/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return {};
        }
        vector<vector<int>> ans;
        queue<Node*> todo;
        todo.push(root);
        while(!todo.empty()){
            int size = todo.size();
            vector<int> level;
            for(int i=0 ; i<size ; i++){
                Node* p = todo.front(); todo.pop();
                level.push_back(p->val);
                for(auto i : p->children)
                    todo.push(i);
            }
            ans.push_back(level);
        }
        return ans;
    }
};