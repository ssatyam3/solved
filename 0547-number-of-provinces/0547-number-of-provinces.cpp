class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &mat){
        vis[node] = 1;
        
        for(int i=0 ; i<mat.size() ; i++){
            if(i==node)
                continue;
            if(!vis[i] && mat[node][i]==1){
                dfs(i,vis,mat);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        vector<int> vis(n,0);
        
        int numOfProvinces=0;
        
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                numOfProvinces++;
                dfs(i,vis,mat);
            }
        }
        return numOfProvinces;
    }
};