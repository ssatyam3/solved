class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        
        int n = g.size();
        if(n==1 && g[0][0]==0)
            return 1;
        if(g[0][0] == 1 || g[n-1][n-1]==1) return -1;
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0] = 1;
        
        while(!q.empty()){
            pair<int,int> p = q.front().first;
            int x = p.first;
            int y = p.second;
            int pathLength = q.front().second;
            q.pop();
            
            int dir[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0},
                             {1,1}, {-1,-1}, {1,-1},{-1,1}};
            for(int i=0 ; i<8 ; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                
                if(nx>=0 && nx<n && ny>=0 && ny<n && g[nx][ny]==0 && vis[nx][ny]==0){
                    q.push({{nx,ny},pathLength+1});
                    vis[nx][ny] = 1;
                    
                    if(nx==n-1 && ny==n-1){
                        return pathLength+1;
                    }
                }
            }
        }
        return -1;
    }
};