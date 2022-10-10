class Solution {
public:
    bool isPalin(string s){
        if(s.length()<2){
            return true;
        }
        int n = s.length();
        for(int i=0; i<n/2 ; i++){
            if(s[i] != s[n-i-1]){
                return false;
            }
        }
        return true;
    }
    string breakPalindrome(string s) {
        int n = s.length();
        if(n==1) return "";
        
        int nnn = 97;
        for(int i=0 ; i<=n ; i++){
            if(i==n){
                s[n-1] = (char)(++nnn);
                return s;
            } else if(s[i] != (char)nnn){
                int ch = s[i];
                s[i] = (char)(nnn);
                if(isPalin(s)){
                    s[i] = ch;
                } else {
                    return s;
                }
            }    
        }
        
        return s;
    }
};