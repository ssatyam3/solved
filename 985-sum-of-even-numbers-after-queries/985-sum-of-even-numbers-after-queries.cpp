class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> ans;
        int sum=0;
        
        
        for(int i=0 ; i<q.size() ; i++){
            if(i==0){
                nums[q[0][1]] = nums[q[0][1]] + q[0][0];
                for(int j=0 ; j<nums.size() ; ++j){
                    if((nums[j]%2)==0) sum+= nums[j];
                }
            } else {
                int ind = q[i][1];
                if(nums[ind]%2==0)
                    sum -= nums[ind];
                nums[ind] = nums[ind] + q[i][0];
                if(nums[ind]%2==0)
                    sum+=nums[ind];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};