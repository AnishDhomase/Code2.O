class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> minFreq(26, 0);
        for(auto word: words2){
            vector<int> freq(26, 0);
            for(auto ch: word)
                freq[ch-'a'] ++;
            for(int i=0; i<26; i++)
                minFreq[i] = max(minFreq[i], freq[i]);
        }
        for(auto word: words1){
            vector<int> freq(26, 0);
            for(auto ch: word)
                freq[ch-'a'] ++;
            bool isUniversal = true;
            for(int i=0; i<26; i++){
                if(freq[i] < minFreq[i]){
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal) ans.push_back(word);
        }
        return ans;
    }
};