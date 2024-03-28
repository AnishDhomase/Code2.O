class Solution {
    bool isAllAtleastK(vector<int> freq, int k){
        for(auto f : freq){
            if(f!=0 && f<k)
                return false;
        }
        return true;
    }
public:
    int longestSubstring(string s, int k) {
        int maxLen=0, n=s.length();
        for(int i=0; i<n; i++){
            vector<int> freq(26,0);
            int ch;
            for(int j=i; j<n; j++){
                ch = s[j]-97;
                freq[ch]++;
                if(freq[ch] >= k && isAllAtleastK(freq, k)){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};