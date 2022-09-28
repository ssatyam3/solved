class Solution {
public:
    //brigde in graph problem
    vector<vector<int>> res;
    
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &tin, int timer, vector<int> &low){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        for(auto it: adj[node]){
            if(it == parent)
                continue;
            
            if(!vis[it]){
                dfs(it,node,adj,vis,tin,timer,low);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]){
                    vector<int> a(2);
                    a[0] = node;
                    a[1] = it;
                    res.push_back(a);
                }
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i=0 ; i<connections.size() ; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        int timer=0;
        
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, tin, timer, low);
            }
        }
        return res;
    }
};