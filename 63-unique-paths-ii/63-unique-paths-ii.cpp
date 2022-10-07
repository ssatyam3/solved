class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1]==1){
            return 0;
        } 
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else {
                        int l=0,r=0;
                        if(i>0 && grid[i][j] == 0) {
                            l = dp[i-1][j];
                        }
                        if(j>0 && grid[i][j]==0) 
                            r = dp[i][j-1];
                        dp[i][j] = l+r;
                    } 
                }
            }
        
        
        return dp[m-1][n-1];
    }
};