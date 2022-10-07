class Solution {
public:
    int f(int i, int j, vector<vector<int>> &arr,vector<vector<int>> &dp){
        if(i==0 && j==0){
            return arr[i][j];
        }
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int up = f(i-1,j,arr,dp);
        int left = f(i,j-1,arr,dp);
        return dp[i][j] = arr[i][j] + min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);
    }
};