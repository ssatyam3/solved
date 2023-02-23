class Solution {
public:
    bool possible(int wt, vector<int> &ws, int d){
            int sum = 0;
            int cnt=1;
        for(int i=0 ; i<ws.size() ; i++){
            sum += ws[i];
            if(sum > wt){
                cnt++;
                sum = ws[i];
            }
        }
        
        return cnt <= d;
    }
    
    int shipWithinDays(vector<int>& ws, int d) {
        
        int mx = INT_MIN;
        int sum = 0;
        
        for(int i=0 ; i<ws.size() ; i++){
            sum += ws[i];
            mx = max(mx,ws[i]);
        }
        
        int lo = mx;
        int hi = sum;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(possible(mid,ws,d)){
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        
        return lo;
    }
};