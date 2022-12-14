class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        //chaining technique
        int count=0;
        int mx=0;
        for(int i=0 ; i<arr.size() ; i++){
            mx = max(mx,arr[i]);
            if(mx == i)
                count++;
        }
        return count;
    }
};