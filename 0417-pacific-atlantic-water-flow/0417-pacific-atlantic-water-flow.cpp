class Solution {
public:
    void dfs(int x, int y, vector<vector<int>> &g, vector<vector<int>> &arr){

        arr[x][y] = 1;
        
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        for(int i=0 ; i<4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx>=0 && ny>=0 && nx<g.size() && ny<g[0].size() &&
                g[x][y] <= g[nx][ny] && arr[nx][ny]==0) {
                dfs(nx,ny,g,arr);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& g) {
        vector<vector<int>> ans;
        int m = g.size();
        int n = g[0].size();
        
        if(m<1) return ans;
        
        vector<vector<int>> pac(m,vector<int>(n,0));
        vector<vector<int>> atl(m,vector<int>(n,0));

        for(int i=0; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(i==0 || j==0){
                    pac[i][j] = 1;
                }
                if(i==m-1 || j==n-1){
                    atl[i][j] = 1;
                }
            }
        }
        
        for(int i=0; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(pac[i][j]==1){
                    dfs(i,j, g, pac);
                }
            }
        }

        for(int i=m-1; i>=0 ; i--){
            for(int j=n-1 ; j>=0 ; j--){
                if(atl[i][j]==1){
                    dfs(i,j, g, atl);
                }
            }
        }
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(pac[i][j]==1 && atl[i][j]==1){
                    vector<int> pair(2);
                    pair[0] = i;
                    pair[1] = j;
                    ans.push_back(pair);
                }
            }
        }
        return ans;
    }
};