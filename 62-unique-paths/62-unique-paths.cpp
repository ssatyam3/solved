class Solution {
public:
    int f(int x, int y, vector<vector<int>> &dp){
        if(x==0 && y==0){
            return 1;
        }
        
        if(dp[x][y] != -1) return dp[x][y];
        int l=0;
            if(x>0){
                l = f(x-1,y,dp);
            }
        int r = 0;
            if(y>0){
                r = f(x,y-1,dp);
            }
        return dp[x][y] = l+r;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
};