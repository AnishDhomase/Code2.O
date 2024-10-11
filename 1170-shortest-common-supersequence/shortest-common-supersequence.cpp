class Solution {
    int getLCS(int i, int j, string &str1, string &str2){
        if(i==0 || j==0)  return 0;

        if(str1[i-1] == str2[j-1])
            return 1 + getLCS(i-1, j-1, str1, str2);
        int p1 = getLCS(i-1, j, str1, str2);
        int p2 = getLCS(i, j-1, str1, str2);
        return max(p1, p2);
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        for(int j=0; j<=n; j++) dp[0][j] = 0;
        for(int i=0; i<=m; i++) dp[i][0] = 0;

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] =  1 + dp[i-1][j-1];
                    continue;
                }
                int p1 = dp[i-1][j];
                int p2 = dp[i][j-1];
                dp[i][j] = max(p1, p2);
            }
        }
        int i=m, j=n;
        string ans; 
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    ans += str1[i-1];
                    i--;
                }
                else{
                    ans += str2[j-1];
                    j--;
                }
            }
        }
        while(i>0){
            ans += str1[i-1];
            i--;
        }
        while(j>0){
            ans += str2[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};