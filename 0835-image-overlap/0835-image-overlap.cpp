class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        int n = img1.size();
        
        vector<pair<int,int>> non_zero_1;
        vector<pair<int,int>> non_zero_2;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(img1[i][j]==1){
                    non_zero_1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    non_zero_2.push_back({i,j});
                }
            }
        }
        
        map<pair<int,int>,int> mp;
        int ans=0;
        
        for(auto [i1,j1] : non_zero_1){
            for(auto [i2,j2] : non_zero_2){
                mp[{j2-j1,i2-i1}]++;
                
                ans = max(ans, mp[{j2-j1,i2-i1}]);
            }
        }
        
        return ans;
    }
};