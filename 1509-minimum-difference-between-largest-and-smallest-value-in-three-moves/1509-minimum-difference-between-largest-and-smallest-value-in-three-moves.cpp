class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n<5) return 0;
        
        sort(nums.begin(),nums.end());
        
        //kill 3 biggest elements
        int res = nums[n-4]-nums[0];
        //kill 3 smallest elements
        res = min(res,nums[n-1]-nums[3]);
        //kill 2 smallest and 1 biggest element
        res = min(res,nums[n-2]-nums[2]);
        //kill 1 smallest and 2 biggest element
        res = min(res,nums[n-3]-nums[1]);
        return res;
    }
};