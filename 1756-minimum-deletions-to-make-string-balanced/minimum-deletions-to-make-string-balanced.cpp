class Solution {
    int getMinDel(int i, int j, string &s, vector<vector<int>> &dp){
        if(i >= j)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        int minOps = 1e9, op = 1e9;
        
        if(s[i] == 'a'){
            if(s[j] == 'b'){
                int op1 = 0 + getMinDel(i, j-1, s, dp);
                int op2 = 0 + getMinDel(i+1, j, s, dp);
                minOps = min(minOps, min(op1, op2));
            }
            else{
                op = 0 + getMinDel(i+1, j, s, dp);
                minOps = min(minOps, op);
            }
        }
        else{
            if(s[j] == 'a'){
                int op1 = 1 + getMinDel(i, j-1, s, dp);
                int op2 = 1 + getMinDel(i+1, j, s, dp);
                minOps = min(minOps, min(op1, op2));
            }
            else{
                op = 0 + getMinDel(i, j-1, s, dp);
                minOps = min(minOps, op);
            }
        }
        return dp[i][j] = minOps;
    }
public:
    int minimumDeletions(string s) {
        // int n = s.length();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return getMinDel(0, n-1, s, dp);
        int Bs = 0, ops = 0;
        for(auto ch : s){
            if(ch == 'b')   Bs ++;
            else if(Bs > 0){
                ops ++;
                Bs --;
            } 
        }
        return ops;
    }
};