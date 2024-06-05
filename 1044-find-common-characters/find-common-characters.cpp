class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        vector<vector<int>> hash(n, vector<int>(26,0));
        for(int i=0; i<n; i++){
            for(auto ch : words[i])
                hash[i][ch-'a']++;
        }
        for(char ch='a'; ch<='z'; ch++){
            int commonFreq = 1e9;
            for(auto h : hash){
                commonFreq = min(commonFreq, h[ch-'a']);
                if(commonFreq == 0) break;
            }
            string chh(1,ch);
            while(commonFreq > 0){
                ans.push_back(chh);
                commonFreq --;

            }
        }
        return ans;

    }
};