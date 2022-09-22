class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int ans=0;
        int min_dif = INT_MAX;
        for(int i=0; i<n-2; i++){
            int lo = i+1, hi = n-1;
            while(lo<hi){
                int sum = nums[i] + nums[lo]+nums[hi];
                if(abs(target - sum) < min_dif){
                    min_dif = abs(target-sum);
                    ans = sum;
                } 
                if(sum > target){
                    hi--;
                } else 
                    lo++;
            }
        }
        return ans;
    }
};