class Solution {
    void addToAns(string str, int start, string &s, unordered_map<string,int> &dict, vector<string> &ans){
        int n = s.length();
        string space = " ";
        if(start==n){ 
            ans.push_back(str); 
            return;
        }  
        for(int i=start; i<n; i++){
            string word = s.substr(start, i-start+1);
            if(dict[word]){  
                if(str != "") addToAns(str + space + word, i+1, s, dict, ans); 
                else  addToAns(word, i+1, s, dict, ans); 
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_map<string,int> dict;
        for(auto w : wordDict)
            dict[w]++;
        addToAns("", 0, s, dict, ans);
        return ans;
    }
};