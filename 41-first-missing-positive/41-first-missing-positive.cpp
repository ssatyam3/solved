class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_map<int,int> seen;
        int i, max = 0;
        for(i=0 ; i<nums.size() ; i++){
            if(nums[i] > max){
                max = nums[i];
            }
            seen[nums[i]]++;
        }
        
        for(i=1 ; i<max ; i++){
            if(seen.count(i) == 0){
                return i;
            }
        }
        
        return max+1;
    }
};