class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length(), cnt = 0;
        vector<vector<int>> mp(26, vector<int>(26, 0));
        for(char ch='a'; ch <= 'z'; ch++){
            int i=0, j=n-1;
            while(i<n && s[i] != ch)   i++;
            while(j>=0 && s[j] != ch)   j--;
            i++; j--;
            int subCnt = 0;
            while(subCnt < 26 && i<=j){
                if(mp[ch-'a'][s[i]-'a'] == 0)    subCnt ++;
                mp[ch-'a'][s[i]-'a'] = 1;
                i++;
            }
            cnt += subCnt;
        }
        return cnt;
    }
};