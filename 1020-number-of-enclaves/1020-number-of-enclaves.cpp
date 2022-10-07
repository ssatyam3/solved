class Solution {
public:
    bool isValid(int r, int c, int m, int n, vector<vector<int>> &grid){
        if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1){
            return true;
        }
        return false;
    }
    void dfs(int row, int col, int m, int n , vector<vector<int>> &grid){
        grid[row][col] = 0;
        
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        
        for(int i=0 ; i<4 ; i++){
            int nx = row + dx[i];
            int ny = col + dy[i];
            
            if(isValid(nx,ny,m,n,grid)){
                dfs(nx,ny,m,n,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0 ; i<m ; i++){
            for(int j=0; j<n ; j++){
                if(i*j==0 || i==m-1 || j==n-1){
                    if(grid[i][j]==1){
                        dfs(i,j,m,n,grid);
                    }
                }
            }
        }
        
        int cnt=0;
        for(int i=0; i < m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};