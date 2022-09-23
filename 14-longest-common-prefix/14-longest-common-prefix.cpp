class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        string ans = "";;
        for(int i=0 ; i<arr[0].length() ; i++){
            if(arr[0][i] == arr[n-1][i]){
                ans += arr[0][i];
            } else {
                break;
            }
        }
        if(ans == "") return "";
        return ans;        
    }
};