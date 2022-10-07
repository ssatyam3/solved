class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(grid[i][j]==1){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int l = f(i-1,j,grid,dp);
        int r = f(i,j-1,grid,dp);
        
        return dp[i][j] = l+r;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1]==1){
            return 0;
        } 
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return f(m-1,n-1,grid,dp);
    }
};