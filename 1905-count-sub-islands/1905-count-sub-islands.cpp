class Solution {
public:
    
    void dfs(int r, int c, int m, int n, int &res, vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
            if(r<0 || r>=m || c<0 || c>=n) return;  
            
            if(grid1[r][c]==0 && grid2[r][c]==1){
                res = false;
            }
            
            if(grid2[r][c]==0) return;
            grid2[r][c] = 0;
            int dx[4] = {-1,0,1,0};
            int dy[4] = {0,-1,0,1};
        
            for(int i=0 ; i<4 ; i++){
                int nx = r + dx[i];
                int ny = c + dy[i];
                
                dfs(nx,ny,m,n,res,grid1,grid2);
            }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        
        int cnt=0;
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid2[i][j]==1 && grid1[i][j]==1){
                    int res = true;
                    dfs(i,j,m,n,res,grid1,grid2);
                    cnt += res;
                }
            }
        }
        return cnt;
    }
};