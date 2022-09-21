//kahn's Algorithm
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> adj;
        
        for(int i=0 ; i<pre.size() ; i++){
            int u = pre[i][0];
            int v = pre[i][1];
            adj[u].push_back(v);
        }
        
        queue<int> q;
        vector<int> indegree(n,0);
        
        for(int i=0 ; i<n ; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0 ; i<n ;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return cnt==n;
    }
};
