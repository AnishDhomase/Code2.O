class Solution {
    bool isPrefixAndSuffix(string &str1, string &str2){
        int n1 = str1.length(), n2 = str2.length();
        if(n2 < n1)   return false;
        if(str2.substr(0, n1) != str1)  return false;
        if(str2.substr(n2-n1, n1) != str1)  return false;
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0, n = words.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isPrefixAndSuffix(words[i], words[j]))
                    cnt ++;
            }
        }
        return cnt;
    }
};