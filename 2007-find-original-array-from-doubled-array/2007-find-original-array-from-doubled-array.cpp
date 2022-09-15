class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans;
        if(n%2==1){
            return ans;
        }
        
        unordered_map<int,int> m;
        for(int i=0 ; i<n ; i++){
            m[changed[i]]++;
        }
        
        sort(changed.begin(),changed.end());
        
        for(int i=0 ; i<n ; i++){
            int ind = changed[i];
            if(ind == 0){
                int freq = m[ind];
                freq = freq/2;
                while(freq--){
                    ans.push_back(0);
                    m[0] = m[0] - 2;
                }
            } else if(m[ind]>0 && m[ind*2]>0){
                ans.push_back(ind);
                m[ind*2]--;
                m[ind]--;
            }
            
        }
        
        if(ans.size()*2 != n){
            vector<int> res;
            return res;
        }
        return ans;
    }
};