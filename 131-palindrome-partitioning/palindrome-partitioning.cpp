class Solution {
    bool isPal(string str){
        int n = str.length();
        for(int i=0; i<n/2; i++){
            if(str[i] != str[n-1-i])
                return false;
        }
        return true;
    }
    void rec(vector<string> subAns, string s,  vector<vector<string>> &ans){
        if(s==""){
            ans.push_back(subAns);
            return;
        }
        for(int i=0; i<s.length(); i++){
            string leftSubString = s.substr(0,i+1);
            string rightSubString = s.substr(i+1);
            if(isPal(leftSubString)){
                subAns.push_back(leftSubString);
                rec(subAns,rightSubString,ans);
                subAns.pop_back();
            }
        }
    }   
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subAns;
        rec(subAns,s,ans);
        return ans;
    }
};