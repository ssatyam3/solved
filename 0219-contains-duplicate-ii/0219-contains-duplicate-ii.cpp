class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> m;
        for(int i=0 ; i<nums.size() ; i++){
            m[nums[i]].push_back(i);
        }
        
        for(int i=0; i<nums.size() ; i++){
            int x = nums[i];
            for(int j=0; j<m[x].size()-1 ; j++){
                if(abs(m[x][j] - m[x][j+1]) <= k)
                    return true;
            }
        }
        
        return false;
    }
};