class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string tmp="";
        for(int i=0 ; i<=s.length() ; i++){
            if(i==s.length()){
                reverse(tmp.begin(),tmp.end());
                ans += tmp;
            }
            else if(s[i] != ' '){
                tmp += s[i];
            } else if(s[i] == ' '){
                reverse(tmp.begin(),tmp.end());
                ans += tmp;
                ans += " ";
                tmp="";
            }
        }

        return ans;
    }
};