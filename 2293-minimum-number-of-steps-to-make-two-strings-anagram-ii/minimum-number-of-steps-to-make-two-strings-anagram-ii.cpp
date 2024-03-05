class Solution {
public:
    int minSteps(string s, string t) {
        int minStep = 0;
        vector<int> freqS(26,0), freqT(26,0);
        for(auto ch : s)
            freqS[ch-97]++;
        for(auto ch : t)
            freqT[ch-97]++;
        for(int i=0; i<26; i++)
            minStep += abs(freqS[i] - freqT[i]);
        return minStep;
        
    }
};