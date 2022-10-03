class Solution {
public:
    int partitionDisjoint(vector<int>& arr) {
        
        int n = arr.size();
        int lmax = arr[0];
        int greater = arr[0];
        int idx=0;
        
        for(int i=0 ; i<n ; i++){
            if(arr[i] < lmax){
                idx = i;
                lmax = greater;
            }
            else if(arr[i] > greater)
                greater = arr[i];
        }
        return idx+1;
    }
};