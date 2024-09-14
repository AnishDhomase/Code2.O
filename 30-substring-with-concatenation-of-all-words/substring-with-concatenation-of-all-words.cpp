class Solution {
    bool isStartingPoint(string &s, unordered_map<string,int> mp, int wordLen){
        int i=0;
        while(i < s.length()){
            string word = s.substr(i, wordLen);
            if(--mp[word] == -1)
                return false;
            i += wordLen;
        }
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.length(), m = words.size(), wordLen = words[0].length();
        unordered_map<string, int> mp;
        for(auto word: words)   mp[word] ++;
        for(int i=0; i<n-(wordLen*m)+1; i++){
            string substr = s.substr(i, wordLen * m);
            if(isStartingPoint(substr, mp, wordLen))
                ans.push_back(i);
        }
        return ans;
    }
};