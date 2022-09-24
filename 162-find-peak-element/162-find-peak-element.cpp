class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo < hi){
            int mi = lo + (hi-lo)/2;
            if(nums[mi] < nums[mi+1]){
                lo = mi+1;
            } else
                hi = mi;
        }
        return lo;
    }
};