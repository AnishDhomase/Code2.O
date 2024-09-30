class Solution {
    void generate(int open, int close, string &subAns, vector<string> &ans, int n){
        if(open == close && open == n){
            ans.push_back(subAns);
            return;
        }
        if(open < n){
            subAns += '(';
            generate(open + 1, close, subAns, ans, n);
            subAns.pop_back();
        }
        if(close < n && close + 1 <= open){
            subAns += ')';
            generate(open, close + 1, subAns, ans, n);
            subAns.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string subAns;
        generate(0,0,subAns,ans,n);
        return ans;
    }
};