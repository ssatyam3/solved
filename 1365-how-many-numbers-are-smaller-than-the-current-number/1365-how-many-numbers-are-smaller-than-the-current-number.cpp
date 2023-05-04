class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
         vector<int> arr(nums.size());
        for(int i=0 ; i<nums.size() ; i++){
            unordered_map<int,int> cnt;
            for(int j=0 ; j<nums.size() ; j++){
                if(i!=j && nums[i]>nums[j] && nums[i]!=nums[j]){
                  //  cout << nums[i] << " " << nums[j] << endl;
                    cnt[nums[i]]++;
                }
                
            }
            arr[i] = cnt[nums[i]];
        }
        
       

        return arr;
    }
};