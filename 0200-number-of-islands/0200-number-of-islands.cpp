class Solution {
public:
    
    void dfs(int row, int col, int n, int m ,vector<vector<char>> &grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        
        if(row-1>=0 && vis[row-1][col]==0 && grid[row-1][col]=='1'){
            dfs(row-1,col,n,m,grid,vis);
        }
        if(col+1<m && vis[row][col+1]==0 && grid[row][col+1] == '1'){
            dfs(row,col+1,n,m,grid,vis);
        }
        if(row+1<n && vis[row+1][col]==0 && grid[row+1][col] == '1'){
            dfs(row+1,col,n,m,grid,vis);
        }
        if(col-1>=0 && vis[row][col-1]==0 && grid[row][col-1] == '1'){
            dfs(row,col-1,n,m,grid,vis);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int ans=0;
        
        for(int i=0; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        
        return ans;
    }
};