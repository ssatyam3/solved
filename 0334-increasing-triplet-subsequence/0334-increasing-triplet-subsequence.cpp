class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        
        int n = arr.size();
        if(n<3){
            return 0;
        }
        
        vector<int> rmax(n+1);
        rmax[n] = INT_MIN;
        for(int i=n-1 ; i>=0 ; i--){
            rmax[i] =  max(rmax[i+1],arr[i]);
        }
        
        int lmin = arr[0];
        for(int i=1 ; i<n-1 ; i++){
            if(arr[i] > lmin && arr[i] < rmax[i+1]){
                return true;
            }
            lmin = min(lmin, arr[i]);
        }
        
        return false;
    }
};