class Solution {
public:
    void dfs(int node, vector<int> &path, vector<vector<int>> &ans,
            vector<vector<int>> &graph){
        
        path.push_back(node);
        if(node == graph.size()-1){
            ans.push_back(path);
        } else {
            for(auto it : graph[node]){
                dfs(it,path,ans,graph);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(0,path,ans,graph);
        return ans;
    }
};