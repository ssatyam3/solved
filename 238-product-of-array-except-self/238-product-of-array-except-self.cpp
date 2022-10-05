class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> index;
        
        int prod=1;
        int prod2=1;
        for(int i=0; i<nums.size() ; i++){
            if(nums[i]==0){
                index.push_back(i);
            } else {
                prod2 *= nums[i];
            }
            prod *= nums[i];
        }
        
        if(index.size()>1){
            vector<int> ans(nums.size(),0);
            return ans;
        }
        
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]!=0){
                nums[i] = prod/nums[i];
            } else {
                nums[i] = prod2;
            }
        }
        return nums;
    }
};