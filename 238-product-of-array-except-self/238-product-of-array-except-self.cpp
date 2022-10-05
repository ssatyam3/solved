class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> rightProd(n);
        rightProd[n-1] = nums[n-1];
        
        int leftProd = 1;
        for(int i=n-2 ; i>=0 ; i--){
            rightProd[i] = nums[i]*rightProd[i+1];
        }
        
        vector<int> ans(n);
        for(int i=0; i<n ; i++){
            if(i==n-1){
                ans[i] = leftProd;
                continue;
            }
            ans[i] = leftProd*rightProd[i+1];
            leftProd *= nums[i];
        }
        
        return ans;
    }
};