class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<int> &visited,int n, int sv){
        if(visited[sv]){
            return;
        }
        visited[sv]=1;
        for(int i=0; i<rooms[sv].size() ; i++){
            if(rooms[sv][i]==sv)
                continue;
            if(!visited[rooms[sv][i]]){
                dfs(rooms,visited,n,rooms[sv][i]);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n  = rooms.size();
        vector<int> visited(n,0);
        dfs(rooms,visited,n,0);
        for(int i=0 ; i<n ; i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
};