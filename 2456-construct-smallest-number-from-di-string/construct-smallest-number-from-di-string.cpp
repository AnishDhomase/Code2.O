class Solution {
    string getNum(string &num, vector<bool> &taken, string &pattern){
        int len = num.length(), n = pattern.length();
        if(len == n+1)  return num;

        for(char ch='1'; ch<='9'; ch++){
            if(taken[ch-'1'])   continue;
            bool isValidNextChar = len==0;
            if(len != 0){
                if(pattern[len-1] == 'I')
                    isValidNextChar = ch > num[len-1];
                else
                    isValidNextChar = ch < num[len-1];
            }
            if(!isValidNextChar) continue;

            num += ch;
            taken[ch-'1'] = true;
            string str = getNum(num, taken, pattern);
            num.pop_back();
            taken[ch-'1'] = false;
            if(str.length() == n+1) return str;
        }
        return "";    
    }
public:
    string smallestNumber(string pattern) {
        vector<bool> taken(9, false);
        string num;
        return getNum(num, taken, pattern);
    }
};