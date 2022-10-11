class Solution {
public:
    void dfs(int x, int y, vector<vector<int>> &g, vector<vector<int>> &vis, 
            queue<pair<int,int>> &q){
        int m = g.size();
        int n = g[0].size();
        
        vis[x][y] = 1;
        q.push({x,y});
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        
        for(int i=0 ; i<4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && ny>=0 && nx<m && ny<n && g[nx][ny]==1 && vis[nx][ny]==0){
                dfs(nx,ny,g,vis,q);
            }
        }
    }
    
    int shortestBridge(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        
        int flag=false;
        
        for(int i=0; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(g[i][j]==1){
                    dfs(i,j,g,vis,q);
                    flag = true;
                }
                if(flag){
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int dx[4] = {-1,0,1,0};
            int dy[4] = {0,-1,0,1};
            
            for(int i=0 ; i<4 ; i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                
                if(nx>=0 && ny>=0 && nx<m && ny<n && vis[nx][ny]==0){
                    if(g[nx][ny] == 1){
                        return g[row][col]-1;
                    } else {
                        g[nx][ny] = g[row][col]+1;
                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                    }  
                }
            }           
            
        }
        return -1;
    }
};