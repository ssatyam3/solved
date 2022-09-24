class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 0, hi = arr.size()-1;
        while(lo < hi){
            int mi = lo + (hi-lo)/2;
            if(arr[mi] < arr[mi+1])
                lo = mi + 1;
            else
                hi = mi;
        }
        return lo;
    }
};