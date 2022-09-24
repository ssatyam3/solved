class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0, h=n-1;

        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid] < target){
                l = mid+1;
            } else 
                h = mid-1;
        }
        return l;
    }
};