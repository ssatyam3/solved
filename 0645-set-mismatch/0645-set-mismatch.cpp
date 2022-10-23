class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        unordered_map<int,int> m;
        int dup = -1, missing = 1;
        for(int i :nums){
            m[i]++;
        }
        
        for(int i=1; i <= nums.size() ; i++){
            if(m.find(i) != m.end()){
                if(m[i]==2){
                    dup = i;
                }
            } else {
                missing = i;
            }
        }
        vector<int> ans(2,0);
        ans[0] = dup;
        ans[1] = missing;
        return ans;
    }
};