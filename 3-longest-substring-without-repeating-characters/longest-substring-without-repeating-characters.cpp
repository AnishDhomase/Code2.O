class Solution {
    bool isRepeatition(unordered_map<char,int> &freq){
        for(auto it=freq.begin(); it!=freq.end(); it++){
            int freqOfChar = (*it).second;
            if(freqOfChar > 1)
                return true;
        }
        return false;
    }
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n = s.length(), maxL=0;
        unordered_map<char,int> freq;
        while(l<=r && r<n){
            freq[s[r]] ++;
            if(! isRepeatition(freq)){
                maxL = max(maxL, r-l+1);
                r ++;
            }
            else {
                freq[s[l]] --;
                l ++;
                r ++;
            }
        }
        maxL = max(maxL, r-l);
        return maxL;
    }
};