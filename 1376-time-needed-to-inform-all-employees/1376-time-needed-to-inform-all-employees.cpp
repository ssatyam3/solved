class Solution {
public:
    
    int dfs(int node, int prevTime, vector<int> &vis, vector<vector<int>> &adj, vector<int>& informTime){
        vis[node] = 1;
        int levelTime = informTime[node];
        int mx=0;
        for(auto it : adj[node]){
            if(!vis[it]){
                int time = dfs(it, levelTime , vis,adj, informTime);
                mx = max(time,mx);
            }
        }
        return mx+prevTime;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>> adj(n);
        vector<int> vis(n,0);
        for(int v=0 ; v<manager.size() ; v++){
            if(manager[v]==-1){
                continue;
            }
            int u = manager[v];
            adj[u].push_back(v);
        }
        int ans=dfs(headID,0, vis, adj, informTime);
        return ans;
    }
};