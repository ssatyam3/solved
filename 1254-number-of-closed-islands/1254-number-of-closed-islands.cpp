class Solution {
public:
    
    bool isValid(int x, int y, int n, int m, vector<vector<int>> &grid){
        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==0){
            return true;
        }
        return false;
    }
    
    void dfs(int x, int y , int n, int m , vector<vector<int>> &grid){
        grid[x][y] = 1;
        
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        
        for(int i=0 ; i<4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isValid(nx,ny,n,m,grid)){
                dfs(nx,ny,n,m,grid);
            }
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(i*j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==0){
                        dfs(i,j, n,m, grid);
                    }
                }
            }
        }
        
        int numberClosedIslands=0;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==0){
                    numberClosedIslands++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return numberClosedIslands;
    }
};