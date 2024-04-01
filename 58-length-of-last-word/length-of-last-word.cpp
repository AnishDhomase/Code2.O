class Solution {
public:
    int lengthOfLastWord(string s) {
        int ct=0;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]!=' '){
                for(; i>=0; i--){
                    if(s[i] != ' '){
                        ct++;
                    }
                    else    return ct;
                }
                break;
            }
        }
        return ct;
    }
};