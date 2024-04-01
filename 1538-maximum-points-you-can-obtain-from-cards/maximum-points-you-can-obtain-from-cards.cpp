class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sumL=0, sumR=accumulate(cardPoints.end()-k, cardPoints.end(), 0);
        int n=cardPoints.size(), i=0, j=n-k, maxScore=sumR;
        for(int i=0,j=n-k;  j<n;  i++,j++){
            sumL += cardPoints[i];
            sumR -= cardPoints[j];
            maxScore = max(maxScore, sumL+sumR);
        }
        return  maxScore;

    }
};