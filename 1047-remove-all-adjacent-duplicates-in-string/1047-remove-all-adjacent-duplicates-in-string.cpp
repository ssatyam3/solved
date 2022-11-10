class Solution {
public:
    string removeDuplicates(string s) {
        
        string res = "";
        res += s[0];
        
        for(int i=1 ; i<s.length() ; i++){
            if(res == ""){
                res += s[i];
            } else {
                if(res[res.length()-1] == s[i]){
                    res.pop_back();
                } else {
                    res += s[i];
                }
            }
        }
        return res;
    }
};