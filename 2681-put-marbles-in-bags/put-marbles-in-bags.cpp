typedef long long LL;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        LL maxScore, minScore;
        int n = weights.size();
        if(n == 1)  return 0;  
        maxScore = minScore = weights[0] + weights[n-1];
        vector<int> adjSumArr;
        for(int i=1; i<n; i++)
            adjSumArr.push_back(weights[i-1] + weights[i]);
        sort(adjSumArr.begin(), adjSumArr.end());
        minScore += accumulate(adjSumArr.begin(), adjSumArr.begin()+k-1, 0LL);
        maxScore += accumulate(adjSumArr.rbegin(), adjSumArr.rbegin()+k-1, 0LL);
        return maxScore - minScore;
    }
};