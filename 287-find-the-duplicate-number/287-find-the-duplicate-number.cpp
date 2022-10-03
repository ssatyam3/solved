class Solution {
public:
    int possible(vector<int> &arr, int num){
        int cnt=0;
        for(int i=0 ; i<arr.size() ; i++){
            if(arr[i]<=num)
                cnt++;
        }
        return cnt;
    }
    int findDuplicate(vector<int>& nums) {
        
        int duplicate = -1;
        int lo=1, hi=nums.size()-1;
        while(lo<=hi) {
            int mi = lo + (hi-lo)/2;
            if(possible(nums,mi) > mi){
                duplicate = mi;
                hi = mi-1;
            } else 
                lo = mi+1;
        }
        return duplicate;
    }
};