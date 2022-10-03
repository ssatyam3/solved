class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        if(n<=1){
            return 0;
        }
        int cost = 0;
        int prev = 0;
        int curr = 1;
        
        while(curr < n && prev < n){
            if(colors[curr] != colors[prev]){
                prev = curr;
                curr++;
            }
            else {
                if(neededTime[curr] < neededTime[prev]){
                    cost += neededTime[curr];
                    curr++;
                } else {
                    cost += neededTime[prev];
                    prev = curr;
                    curr++;
                }
            }
        }
        
        return cost;
    }
};