class Solution {
public:
    int partitionDisjoint(vector<int>& arr) {
        int n = arr.size();
        vector<int> rightmin(n+1);
        rightmin[n] = INT_MAX;
        
        for(int i=n-1 ; i>=0 ; i--){
            rightmin[i] = min(rightmin[i+1],arr[i]);
        }
        
        int lmax = INT_MIN;
        int ans=0;
        for(int i=0; i<n ; i++){
            lmax = max(lmax,arr[i]);
            if(lmax <= rightmin[i+1]){
                ans = i;
                break;
            }
        }
        return ans+1;
    }
};