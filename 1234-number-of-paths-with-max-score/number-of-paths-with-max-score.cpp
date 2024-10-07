class Solution {
    int mod = 1e9 + 7;
    vector<int> getMaxPath(int r, int c, vector<string>& board, vector<vector<vector<int>>> &dp){
        if(board[r][c] == 'X')  return {0,0};
        if(board[r][c] == 'E')  return {0,1};

        if(dp[r][c][0] != -1)   return dp[r][c];

        vector<int> left={0,0}, diag={0,0}, up={0,0};
        if(c-1 >= 0)    
            left = getMaxPath(r, c-1, board, dp);
        if(c-1 >= 0 && r-1 >= 0)    
            diag = getMaxPath(r-1, c-1, board, dp);
        if(r-1 >= 0)    
            up = getMaxPath(r-1, c, board, dp);
        
        vector<int> ans = { max(left[0], max(diag[0], up[0])), 0};
        vector<vector<int>> options={left, diag, up};
        for(auto opt : options){
            if(opt[0] == ans[0])
                ans[1] = (ans[1] + opt[1]) % mod;
        }
        if(board[r][c] != 'S')
            ans[0] = (ans[0] + (board[r][c] - 48)) % mod;
        if(ans[1] == 0) return dp[r][c] = {0,0};
        return dp[r][c] = ans;
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int> (2,-1)));
        return getMaxPath(n-1, n-1, board, dp);
    }
};