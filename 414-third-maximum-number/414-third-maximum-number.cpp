class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int,greater<int>> s;
        
        for(int i=0; i<nums.size() ; i++)
            s.insert(nums[i]);
        
        if(s.size()<3)
            return *s.begin();
        
        int ans=0;
        int itr=1;
        for(auto i : s){
            if(itr==3){
                ans = i;
                return ans;
            }
            itr++;
        }
        return ans;
    }
};