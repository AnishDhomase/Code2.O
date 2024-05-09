class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long max = 0;
        int n = happiness.size(), i, dec;
        sort(happiness.begin(), happiness.end());
        for(i=n-1, dec=0; k && i>=0; i--,dec++, k--){
            if(happiness[i]-dec >= 0){
                max += happiness[i]-dec;
            }
            else    break;
        }
        return max;
    }
};