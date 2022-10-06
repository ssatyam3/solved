class Solution {
public:
    void dfs(int row, int col, int n, int m, int& area, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[row][col]= 1;
        area++;
        if(row>=1 && vis[row-1][col]==0 && grid[row-1][col]==1){
            dfs(row-1,col,n,m,area,vis,grid);
        }
        if(col>=1 && vis[row][col-1]==0 && grid[row][col-1]==1){
            dfs(row,col-1,n,m,area,vis,grid);
        }
        if(row+1<n && vis[row+1][col]==0 && grid[row+1][col]==1){
            dfs(row+1,col,n,m,area,vis,grid);
        }
        if(col+1<m && vis[row][col+1]==0 && grid[row][col+1]==1){
            dfs(row,col+1,n,m,area,vis,grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int mxarea=0;
        int area=0;
        
        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    area=0;
                    dfs(i,j,n,m,area,vis,grid);
                    mxarea = max(mxarea,area);
                }
            }
        }
        return mxarea;
    }
};