class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans=-1;
        vector<int> people(n+1,0);
        for(int i=0 ; i<trust.size() ; i++){
            people[trust[i][0]]--;
            people[trust[i][1]]++;
        }
        
        for(int i=1 ; i<=n ; i++){
            if(people[i]==n-1){
                return i;
            }
        }
        return ans;
    }
};