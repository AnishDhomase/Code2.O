class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), l=0, r=0, maxL = 0;
        vector<int> mp(26,0);
        while(r < n){
            mp[s[r] - 'A'] ++;
            if((r-l+1) - *max_element(mp.begin(), mp.end()) > k){
                mp[s[l] - 'A'] --;
                l ++;
            }
            if((r-l+1) - *max_element(mp.begin(), mp.end()) <= k)
                maxL = max(maxL, r-l+1);
            r ++;
        }
        return maxL;
    }
};