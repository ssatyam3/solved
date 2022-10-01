class Solution {
public:
    unordered_map<string,int> mp;
    
    int dfs(string str, int start, int end){
        if(start > end){
            return 1;
        }
        if(str[start]=='0'){
            return 0;
        }
        if(start==end){
            if(str[start] == '0'){
                return 0;
            }
            int x = str[start] - '0';
            if(x>=1 && x<=26){
                return 1;
            }
        }
        int ans=0;
        int x = str[start] - '0';
        if(x>=1 && x<=26){
            string tmp = str.substr(start+1,end-start);
            if(mp.find(tmp)==mp.end()){
                mp[tmp] = dfs(str, start+1, end);
            }
            ans += mp[tmp];
        }
        
        int z = stoi(str.substr(start,2));
        if(z>=10 && z<=26){
            string tmp = str.substr(start+2,end-start-1);
            if(mp.find(tmp) == mp.end()){
                mp[tmp] = dfs(str, start+2, end);
            }
            ans += mp[tmp];
        }
        return ans;
    }
        
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        return dfs(s, 0, s.length()-1);
    }
};