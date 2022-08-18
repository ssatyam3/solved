class Solution {
public:
    //Trailing 0s in N! = Count of 5s in prime factors of n!
    //              = floor(n/5) + floor(n/25) + floor(n/125) + ....
    int trailingZeroes(int n) {
        int res=0;
        for(long i=5 ; n/i>0 ; i*=5){
            res += (n/i);
        }
        return res;
    }
};