class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        int n=s.length();
        
        for(int i=0 ; i<n ; i++){
            mp[s[i]] = i; 
        }
        
        vector<int> ans;
        int mx=0;
        int ind=0;
        for(int i=0 ; i<n ; i++){
            mx = max(mp[s[i]],mx);
            if(mx==i){
                int len = i-ind+1;
                ans.push_back(len);
                ind=i+1;
            }
        }
        return ans;
    }
};