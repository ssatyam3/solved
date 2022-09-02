class Solution {
public:
    int reverse(int x) {
        long sign = (x>0) ? 1 : -1;
        long res=0;
        x = abs(x);
        while(x>0){
            res = res*10 + x%10;
            x = x/10;
        }
        res = res*sign;
        if(res < -1*pow(2,31) || res > (pow(2,31)-1))
            return 0;
        return (int)res;
    }
};