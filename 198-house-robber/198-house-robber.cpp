class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        
        int prev = arr[0];
        int prev2 = -1;
        for(int i=1 ; i<n ; i++){
            
            int pick = arr[i];
            if(prev2 != -1)
                pick += prev2;
            int notpick = prev;
            int curi = max(pick,notpick);
            
            prev2 = prev;
            prev = curi;
        
        }
        
        return prev;
    }
};