class Solution {
public:
    string pushDominoes(string s) {
        int l=-1,r=-1;
        for(int i=0 ; i<=s.length() ; i++){
            if(i==s.length() || s[i]=='R'){
                if(r>l){ // R....R
                    while(r<i)
                        s[r++] = 'R';
                }// else L...R that is do nothing
                r = i;
            } else if(s[i] == 'L'){
                if(l>r || r==-1){ // L...L
                    while(++l<i){
                        s[l] = 'L';
                    }
                } else { // R...L
                    l = i;
                    int lo = r+1, hi = l-1;
                    while(lo<hi){
                        s[lo++] = 'R';
                        s[hi--] = 'L';
                    }
                }
            }
        }
        return s;
    }
};