class Solution {
public:
    string makeGood(string s) {
        if(s.length()<2){
            return s;
        }
        
        string str = "";
        str += s[0];
        
        for(int i=1 ; i<s.length() ; i++){
            if(str.empty()){
                str += s[i];
            } else {
                int a1 = (int)str[str.length()-1];
                int a2 = (int)s[i];
                if(abs(a1-a2) != 32){
                    str += s[i];
                } else {
                    str.pop_back();
                }
            }
        }
        return str;
    }
};