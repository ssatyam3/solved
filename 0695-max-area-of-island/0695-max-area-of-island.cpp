class Solution {
public:
    int dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size() || 
                vis[row][col] == 1 || grid[row][col] == 0)
            return 0;
        
        vis[row][col]= 1;
        return (1 + dfs(row-1,col,vis,grid) + dfs(row,col+1,vis,grid)
               + dfs(row+1,col,vis,grid) + dfs(row,col-1,vis,grid));
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int mxarea=0;
        
        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area = dfs(i,j,vis,grid);
                    mxarea = max(mxarea,area);
                }
            }
        }
        return mxarea;
    }
};