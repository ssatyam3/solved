class Solution {
public:
    int strStr(string heystack, string needle) {
        int len1 = heystack.length();
        int len2 = needle.length();
        if(len2 > len1)
            return -1;
        if(len1==len2 && heystack==needle)
            return 0;
        
        for(int i=0 ; i<len1-len2+1 ; i++){
            if(heystack.substr(i,len2) == needle){
                return i;
            }
        }
        return -1;
    }
};