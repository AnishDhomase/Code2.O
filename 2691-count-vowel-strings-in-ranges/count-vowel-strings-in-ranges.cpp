class Solution {
    bool isVowelChar(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    bool isVowelString(string w){
        int wLen = w.length();
        char charL = w[0], charR = w[wLen-1];
        if(!isVowelChar(charL)) return false;
        if(!isVowelChar(charR)) return false;
        return true;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int qSize = queries.size(), wSize = words.size();
        vector<int> ans, preSum;
        int cnt = 0;
        for(int i=0; i<wSize; i++){
            if(isVowelString(words[i])) cnt ++;
            preSum.push_back(cnt);
        }
        for(auto q: queries){
            int l = q[0], r = q[1];
            int vowelStringCnt = preSum[r] - (l-1 == -1 ? 0 : preSum[l-1]);
            ans.push_back(vowelStringCnt);
        }
        return ans;
    }
};