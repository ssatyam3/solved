class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0){
            return 0;
        } 
        if(tokens.size()==1){
            return power > tokens[0] ? 1 : 0;
        }
        sort(tokens.begin(),tokens.end());
        int lo = 0, hi = tokens.size()-1;
        int score = 0;
        while(lo<hi){
            if(power>=tokens[lo]){
                power -= tokens[lo];
                score++; lo++;
            }
            else if(score >= 1){
                power += tokens[hi];
                score--; hi--;
            } else {
                lo++; hi--;
            }
        }
        
        if(lo==hi && power>=tokens[lo]){
            score++;
        }
        return score;
    }
};