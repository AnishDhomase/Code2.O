class Solution {
    bool isPossibleAns(unordered_map<char, int> &mpt,  unordered_map<char, int> &mpWindow){
        for(auto it: mpt){
            char ch = it.first;
            int reqFreq = it.second;
            if(mpWindow[ch] < reqFreq)
                return false;
        }
        return true;
    }   
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpt, mpWindow;
        for(auto ch: t) mpt[ch] ++;
        int i=0, j=0, n=s.length();
        string ans = s + ' ';
        while(i<=j && j<n){
            mpWindow[s[j]] ++;
            if(isPossibleAns(mpt, mpWindow)){
                while(mpt[s[i]] < mpWindow[s[i]]){
                    mpWindow[s[i]] --;
                    i ++;
                } //trim it from left to minimum possible
                if((j-i+1) < ans.length())
                    ans = s.substr(i, j-i+1);
                mpWindow[s[i]] --;
                i ++;
                j ++;
                    
            }
            else{
                j ++;
            }

        } 
        if(ans.length() == n+1) return "";
        return ans;
    }
};