class Solution {
public:
    
    bool biPartite(int node, vector<vector<int>>& adj, vector<int> &color){
        if(color[node] == -1)
            color[node] = 0;
        
        for(auto it : adj[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                if(!biPartite(it, adj, color)){
                    return false;
                }
                
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n,-1);
        
        for(int i=0 ; i<n; i++){
            if(color[i] == -1){
                if(!biPartite(i,adj,color)){
                    return false;
                }
            }
        }
        return true;
    }
};