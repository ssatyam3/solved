class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miniPrice = INT_MAX;
        int maxPro=0;
        for(int i=0 ; i<prices.size() ; i++){
            miniPrice = min(miniPrice,prices[i]);
            maxPro = max(maxPro,prices[i]-miniPrice);
        }
        return maxPro;
    }
};