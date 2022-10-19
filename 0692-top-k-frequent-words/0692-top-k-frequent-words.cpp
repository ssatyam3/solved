class Solution {
public:
    struct Compare {
        bool operator() (pair<int, string> a, pair<int, string> b) {
            if(a.first == b.first)
                return a.second > b.second;
            else
                return a.first < b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(int i=0 ; i<words.size() ; i++){
            string s = words[i];
            m[s]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        
        vector<string> ans;
        for(int i=0; i<k ; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};