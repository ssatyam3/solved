class Solution {
public:
    // 1. make adjacency list count the edges also
    // 2. calculate the no. of components
    // 3. redundant edges = total edges - ((N-1) - (no. of components - 1))
    // 4. if redundant edges >= components-1 then we need (components - 1) edges to connect the graph
    // 5. if redundant edges < N-1 return -1
    // 6. if redundant edges < components - 1 return -1
    
    void dfs(int node, vector<int> &vis, unordered_map<int,vector<int>> &adj){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> vis(n,0);
        unordered_map<int,vector<int>> adj;
        int edges=0;
        
        for(int i=0 ; i<connections.size() ; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges++;
        }
        
        int components=0;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                components++;
                dfs(i,vis,adj);
            }
        }
        
        int red = edges - ((n-1) - (components-1));
        if(red < components-1){
            return -1;
        }
        else if(edges < n-1){
            return -1;
        }
        return components-1;
    }
};