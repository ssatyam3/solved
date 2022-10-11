class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& en) {
        
        int m = maze.size();
        int n = maze[0].size();
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{en[0],en[1]},0});
        
        while(!q.empty()){
            pair<int,int> pp = q.front().first;
            
            int row = pp.first;
            int col = pp.second;
            int dist = q.front().second;
            q.pop();
            maze[row][col] = '+';
            
            int dx[4] = {-1,0,1,0};
            int dy[4] = {0,-1,0,1};
            for(int i=0; i<4 ; i++){
                int nx = row + dx[i];
                int ny = col + dy[i];
                
                if(nx>=0 && ny>=0 && nx<m && ny<n && maze[nx][ny]!='+'){
                    if(nx==0 || ny==0 || nx==m-1 || ny==n-1){
                        return dist+1;
                    } else {
                        q.push({{nx,ny},dist+1});
                        maze[nx][ny] = '+';
                    }
                }
            }
        }
        
        return -1;
    }
};