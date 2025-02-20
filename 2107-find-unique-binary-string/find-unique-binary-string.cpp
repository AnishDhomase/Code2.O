class Solution {
    string getDifferentString(string &str, set<string> &st, int n){
        int len = str.length();
        if(len == n){
            if(st.find(str) == st.end())    return str;
            return "";
        }
        for(char ch='0'; ch<='1'; ch++){
            str += ch;
            string res = getDifferentString(str, st, n);
            str.pop_back();
            if(res.length() == n)   return res;
        }
        return "";      
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string str;
        int n = nums.size();
        set<string> st(nums.begin(), nums.end());
        return getDifferentString(str, st, n);
    }
};