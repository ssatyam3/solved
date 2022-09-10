class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimal = INT_MAX;
        int ans=0;
        for(int i=0 ; i<prices.size() ; i++){
            if(minimal > prices[i]) minimal = prices[i];
            ans = max(ans,prices[i] - minimal);
        }
        return ans;
    }
};