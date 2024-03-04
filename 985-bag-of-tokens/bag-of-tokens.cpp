class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n=tokens.size(), i=0, j=n-1, score=0, maxS=0;
        while(i<=j){
            if(!score){
                if(tokens[i] <= power){
                    power -= tokens[i];
                    score++;
                    i++;
                }
                else    break;
            }
            else{
                if(tokens[i] <= power){
                    power -= tokens[i];
                    score++;
                    i++;
                }
                else{
                    power += tokens[j];
                    score--;
                    j--;
                }
            }
            maxS = maxS > score ? maxS : score;
        }
        return maxS;
    }
};