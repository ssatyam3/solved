class Solution {
public:
    // house robber 1 is used 
    int helper(vector<int>& arr) {
        int n = arr.size();
        
        int prev = arr[0];
        int prev2 = -1;
        for(int i=1 ; i<n ; i++){
            
            int pick = arr[i];
            if(prev2 != -1)
                pick += prev2;
            int notpick = prev;
            int curi = max(pick,notpick);
            
            prev2 = prev;
            prev = curi;
        
        }
        
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp1,temp2;
        
        for(int i=0 ; i<n ; i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        
        return max(helper(temp1), helper(temp2));
    }
};