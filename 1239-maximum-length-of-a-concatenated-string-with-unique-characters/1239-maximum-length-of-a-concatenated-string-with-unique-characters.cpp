class Solution {
public:
    int f(int idx, int len, unordered_map<char, int> &seen, vector<string> &arr){
        if(idx>=arr.size()){
            return len;
        }
        bool z = false;
        for(int i=0 ; i<arr[idx].length() ; i++){
            if(seen.find(arr[idx][i]) != seen.end()){
                z = true;
            }
        }
        bool flag = false;
        for(int i=0 ; i<arr[idx].length() ; i++){
            if(seen[arr[idx][i]]>0){
                flag = true;
            }
            seen[arr[idx][i]]++;
        }
        int pick = -1;
        if(!flag && !z){
            len = len + arr[idx].length();
            pick = f(idx+1, len, seen,arr);
        
            len = len - arr[idx].length();\
        }
        for(int i=0 ; i<arr[idx].length() ; i++){
            seen[arr[idx][i]]--;
            if(seen[arr[idx][i]]==0){
                seen.erase(arr[idx][i]);
            }
        }
        int notpick = f(idx+1, len, seen, arr);
        
        return max(pick,notpick);
    }
    
    int maxLength(vector<string>& arr) {
        
        unordered_map<char,int> seen;
        int ans = f(0,0,seen,arr);
        return ans;
    }
};