class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        vector<string> ans;
        string word;
        for(auto ch: s1){
            if(ch == ' '){
                freq[word] ++;
                word = "";
            }
            else word += ch;
        }
        freq[word] ++;
        word = "";
        for(auto ch: s2){
            if(ch == ' '){
                freq[word] ++;
                word = "";
            }
            else word += ch;
        }
        freq[word] ++;
        for(auto it: freq){
            if(it.second == 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};