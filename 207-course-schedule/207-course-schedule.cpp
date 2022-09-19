class Solution {
public:
    
    bool dfs(int node, unordered_map<int,vector<int>> &adj, vector<int> &vis, vector<int> &dfsVis){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto it : adj[node]){
            if(vis[it]==0){
                if(dfs(it,adj,vis,dfsVis)){
                    return true;
                }
            } else if(dfsVis[it]){
                return true;
            }
        }
        dfsVis[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        if(pre.size()<=1){
            return true;
        }
        unordered_map<int,vector<int>> adj;
        int m = pre.size();
        for(int i=0 ; i<m ; i++){
            int u = pre[i][0];
            int v = pre[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(n,0);
        vector<int> dfsVis(n,0);
        
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                if(dfs(i , adj, vis, dfsVis)){
                    return false;
                }
            }
        }
        return true;
    }
};