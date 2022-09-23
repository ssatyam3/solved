class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string res="",tmp="";
        for(int i=0 ; i<=n ; i++){
            if((s[i]==' ' || i==n) && tmp != ""){
                res = tmp + ' ' + res;
                tmp="";
            } else if(s[i] != ' '){
                tmp += s[i];
            }
        }
        res.pop_back();
        return res;
    }
};