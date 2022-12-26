class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length<=1){
            return true;
        }
        if(nums[0] == 0) {
            return false;
        }
        int possible = nums[0];
        for(int i=1 ; i<nums.length ; i++){
            possible--;
            if(i==nums.length-1){
                break;
            }
            if(possible < nums[i]){
                possible = nums[i];
            } else if(possible==0 && i!=nums.length-1) {
                return false;
            }
        }
        return true;
    }
}