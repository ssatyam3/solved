class Solution {
public:
    
    bool vowel(char s){
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'
              || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U'){
                return 1;
            }   
        return 0;
    }
    
    bool halvesAreAlike(string s) {
        
        int cnt1=0,cnt2=0;
        int i=0;
        for( ; i<s.length()/2 ; i++){
            if(vowel(s[i])){
                cnt1++;
            }
        }
        
        for(int ; i<s.length() ; i++){
            if(vowel(s[i])){
                cnt2++;
            }
        }
        
        return cnt1==cnt2;
    }
};