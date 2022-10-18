class Solution {
public:

    string countAndSay(int n) {
        
        string res = "1";
        for(int i=1 ; i<n ; i++){
            string cur = "";
            for(int i=0 ; i<res.size() ; i++){
                int cnt=1;
                while((i+1<res.size()) && (res[i] == res[i+1])){
                    cnt++;
                    i++;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
};