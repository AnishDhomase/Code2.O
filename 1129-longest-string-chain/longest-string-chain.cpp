bool lenComp(string &s1, string &s2){
    return s1.length() < s2.length();
}
class Solution {
    bool isValidChainSeq(string &prev, string &curr){
        if(prev.length() + 1 != curr.length())  return false;
        int i=0, j=0, n=prev.length();
        int diff = 0;
        while(i<n && j<n+1){
            if(prev[i] != curr[j]){
                j ++;
                diff ++;
                if(diff == 2)   return false;
            }  
            else{
                i ++;
                j ++;
            }
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), lenComp);
        vector<int> len(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isValidChainSeq(words[j], words[i]))
                    len[i] = max(len[i], 1 + len[j]);
            }
        }
        return *max_element(len.begin(), len.end());
    }
};