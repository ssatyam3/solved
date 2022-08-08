typedef long long int ll;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        ll good_pairs=0;
        ll n = nums.size();
        
        map<int,int> prev;
        for(int i=0 ; i<n ; i++){
            int curr = i-nums[i];
            good_pairs += prev[curr];
            prev[curr]++;
        }
        ll total = n*(n-1)/2;
        return (total-good_pairs);
    }
};
