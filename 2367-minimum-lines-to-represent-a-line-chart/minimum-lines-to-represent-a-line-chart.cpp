class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end());
        int n, cnt, dy, dx, pdy, pdx;

        n = stockPrices.size();
        cnt = 1;
        if(n == 1) return 0;

        pdy = stockPrices[1][1] - stockPrices[0][1];
        pdx = stockPrices[1][0] - stockPrices[0][0];

        for(int i=2; i<n; i++){
            dy = stockPrices[i][1] - stockPrices[i-1][1];
            dx = stockPrices[i][0] - stockPrices[i-1][0];

            if((long long)pdy * dx != (long long) pdx * dy) {
                cnt ++;
                pdy = dy;
                pdx = dx;
            }
        }
        return cnt;
    }
};