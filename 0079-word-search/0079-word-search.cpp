class Solution {
public:
    
    bool isValid(int r, int c, int ind ,int m, int n, vector<vector<char>> &board, string &word, vector<vector<int>> &vis){
        if(r<0 || r>=m || c<0 || c>=n || board[r][c] !=  word[ind] || vis[r][c]==1){
            return false;
        }
        return true;
    }
    
    void dfs(int r, int c, int ind, int m, int n, bool &res, vector<vector<char>> &board, string &word, vector<vector<int>> &vis){
        
        if(ind==word.length()-1){
            res = true;
            return;
        }
        vis[r][c] = 1;

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        for(int i=0 ; i<4 ; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];
            
            
            if(isValid(nx,ny,ind+1,m,n, board, word, vis)){
                dfs(nx,ny, ind+1,m,n,res,board,word,vis);
            }
        }
        vis[r][c] = 0;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == word[0]){
                    bool res = false;
                    dfs(i,j,0,m,n,res,board,word,vis);
                    if(res)
                        return true;
                }
            }
        }
        return false;
    }
};