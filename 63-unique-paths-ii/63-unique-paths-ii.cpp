class Solution {
public:
    // Space optimized solution
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1]==1){
            return 0;
        } 
        
        vector<int> prev(n,0);
        
        for(int i=0 ; i<m ; i++){
            vector<int> cur(n,0);
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    cur[j] = 0;
                }
                else if(i==0 && j==0){
                    cur[j] = 1;
                }
                else {
                        int l=0,r=0;
                        if(i>0) {
                            l = prev[j];
                        }
                        if(j>0) 
                            r = cur[j-1];
                        cur[j] = l+r;
                    } 
                }
            prev = cur;    
        }
        
        
        return prev[n-1];
    }
};