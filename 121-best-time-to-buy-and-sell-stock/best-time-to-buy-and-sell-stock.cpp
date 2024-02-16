class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProf = 0, buy = prices[0];
        for(int i=1; i<n; i++){
            if(prices[i] > buy){
                int currProf = prices[i] - buy;
                maxProf = currProf > maxProf ? currProf : maxProf;
            }
            else{
                buy = prices[i];
            }
        }
        return maxProf;
    }
};