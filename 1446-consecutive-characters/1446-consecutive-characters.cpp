class Solution {
public:
    int maxPower(string s) {
        int mx=1,c=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                c++;
            }else{
                mx=max(mx,c);
                c=1;
            }
        }
        mx=max(mx,c);
        return mx;
    }
};