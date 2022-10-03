class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int n){
        vis[node] = 1;
        for(int i=0 ; i<n ; i++){
            if(!vis[i] && adj[node][i] == 1){
                dfs(i,adj,vis,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n,0);
        
        int cnt=0;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                cnt++;
                dfs(i ,adj,vis,n);
            }
        }
        return cnt;
    }
};