class Solution {
public:
    // Space optimized solution
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> prev(n,0);
        
        for(int i=0 ; i<m ; i++){
            vector<int> cur(n,0);
            for(int j=0 ; j<n ; j++){
                if(i==0 && j==0) cur[j]=grid[i][j];
                else {
                    int l=INT_MAX,r=INT_MAX;
                    if(i>0) l = prev[j];
                    if(j>0) r = cur[j-1];
                    cur[j] = grid[i][j] + min(l,r);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};