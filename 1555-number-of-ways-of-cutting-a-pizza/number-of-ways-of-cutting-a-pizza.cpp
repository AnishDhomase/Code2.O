typedef long long LL;
class Solution {
    int mod = 1e9 + 7;
    int getWays(int r, int c, int cuts, vector<string>& pizza, vector<vector<vector<int>>> &dp){
        int rows = pizza.size(), cols = pizza[0].size();

        if(cuts == 0){
            for(int i=r; i<rows; i++){
                for(int j=c; j<cols; j++)
                    if(pizza[i][j] == 'A')
                        return 1;                       
            }
            return 0;
        };
        if(dp[r][c][cuts] != -1)    return dp[r][c][cuts];

       
        int minRowAfterCutPossible = rows, minColAfterCutPossible = cols;
        for(int i=r; i<rows; i++){
            for(int j=c; j<cols; j++)
                if(pizza[i][j] == 'A'){
                    minRowAfterCutPossible = i;
                    break;
                } 
            if(minRowAfterCutPossible != rows)  break;                 
        }
        for(int j=c; j<cols; j++){
            for(int i=r; i<rows; i++)
                if(pizza[i][j] == 'A'){
                    minColAfterCutPossible = j;
                    break;
                } 
            if(minColAfterCutPossible != cols)  break;                  
        }

        LL ways = 0;
        for(int verCut = minColAfterCutPossible + 1; verCut < cols; verCut ++)   
            ways = ((LL)ways + getWays(r, verCut, cuts-1, pizza, dp)) % mod;
        for(int horCut = minRowAfterCutPossible + 1; horCut < rows; horCut ++)    
            ways = ((LL)ways + getWays(horCut, c, cuts-1, pizza, dp)) % mod;
        return dp[r][c][cuts] = ways;
    }
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k, -1)));
        return getWays(0, 0, k-1, pizza, dp);
    }
};