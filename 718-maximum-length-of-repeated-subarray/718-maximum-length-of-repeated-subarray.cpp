class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        int ans=0;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(ans >= n-i) return ans;
                if(nums1[i]==nums2[j]){
                    int cnt=0;
                    int a=i, b=j;
                    while(a<n && b<m && nums1[a++] == nums2[b++]){
                        cnt++;
                    }
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};