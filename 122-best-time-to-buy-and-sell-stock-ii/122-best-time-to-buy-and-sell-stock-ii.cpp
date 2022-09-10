class Solution {
public:
    int maxProfit(vector<int>& ps) {
        int ans=0,res=0, n=ps.size();
        int minimum=INT_MAX;
        for(int i=0 ; i<n ; i++){
            minimum = min(minimum, ps[i]);
            res = max(res, ps[i]-minimum);
            if(i<n-1){
                ans += (ps[i+1]-ps[i]>0) ? ps[i+1] -ps[i] : 0;
            }
        }
        return ans>res ? ans : res;
    }
};