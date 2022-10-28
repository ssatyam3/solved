class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> umap;
        
        for(string x : strs){
            string tmp = x;
            sort(tmp.begin(), tmp.end());
            umap[tmp].push_back(x);
        }
        
        vector<vector<string>> ans;
        
        for(auto i : umap){
            vector<string> vec = i.second;
            ans.push_back(vec);
        }
        return ans;
    }
};