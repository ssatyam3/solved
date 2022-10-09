class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& g) {
        
        int m = g.size();
        int n = g[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0 ; i<m ; i++){
            for(int j=0; j<n ; j++){
                if(g[i][j]==0){
                    q.push({i,j});
                } else if(g[i][j] == 1){
                    g[i][j] = -1;
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int dx[4] = {-1, 0 ,1, 0};
            int dy[4] = {0, -1, 0, 1};
            
            for(int i=0 ; i<4 ; i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                
                if(nx<0 || nx>=m || ny<0 || ny>=n){
                    continue;
                }
                else if(g[nx][ny]==-1){
                    g[nx][ny] = g[row][col] + 1;
                    q.push({nx,ny});
                }
            }
        }
        return g;
    }
};