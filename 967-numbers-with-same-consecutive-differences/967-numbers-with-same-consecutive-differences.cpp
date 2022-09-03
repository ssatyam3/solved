class Solution {
public:
    
    void dfs(int n, int num, int k, vector<int> &res){
        if(n==0){
            res.push_back(num);
            return;
        }
        vector<int> nextDigits;
        
        int tailDigit = num%10;
        nextDigits.push_back(tailDigit + k);
        if(k!=0)
            nextDigits.push_back(tailDigit - k);
        
        for(auto i : nextDigits){
            if(0 <= i && i < 10){
                int newNum = num*10 + i;
                dfs(n-1,newNum,k,res);
            }
        }       
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n==1){
            vector<int> v;
            for(int i=0; i<=9 ; i++) v.push_back(i);
            return v;
        }
        vector<int> res;
        for(int num=1 ; num<10 ; num++){
            dfs(n-1, num, k, res);
        }
        return res;
    }
};