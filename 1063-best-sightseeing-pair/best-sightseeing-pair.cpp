class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), maxV = values[0], score = INT_MIN;
        for(int i=1; i<n; i++){
            score = max(score, maxV + values[i] - i);
            maxV = max(maxV, values[i] + i);
        }
        return score;
    }
};