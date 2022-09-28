class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int findParent(int node) {
        return parent[node] == node ? node : (parent[node] = findParent(parent[node]));
    }    
    void makeSameGroup(int u , int v) {
        int pu = findParent(u) ; 
        int pv = findParent(v);
        
        if(pu != pv){
            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            } else if(rank[pv] < rank[pu]){
                parent[pv] = pu;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i; 
            rank[i] = 0;
        }
        
        for(auto e : edges) {
            makeSameGroup(e[0] , e[1]); 
        }                         
        return findParent(start) == findParent(end); 
    }
};