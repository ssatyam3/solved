class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i=nums.size()-1 ; i>=0 ; i--){
            if(nums[i]==val){
                k++;
                for(int j=i; j<nums.size()-1 ; j++){
                    nums[j] = nums[j+1];
                }
            }
        }
        return nums.size() - k;
    }
};