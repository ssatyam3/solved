class Solution {
public:
    bool canWinNim(int n) {
        if(n==1 || n==2 || n==3){
            return 1;
        }
       int a = (n-1)%4;
        int b = (n-2)%4;
        int c = (n-3)%4;
        return (!a || !b || !c);
    }
};