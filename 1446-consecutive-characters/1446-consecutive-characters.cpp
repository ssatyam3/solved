class Solution {
public:
    int maxPower(string s) {
        if(s.length() < 1)
            return 0;
        int cnt=1;
        int mx=1;
        
        for(int i=1 ; i<s.length() ; i++){
            if(s[i] == s[i-1]){
                cnt++;
            } else {
                cnt=1;
            }
            mx = max(mx,cnt);
        }
        return mx;
    }
};