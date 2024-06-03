class Solution {
public:
    int appendCharacters(string s, string t) {
        int lenS = s.length(), lenT = t.length();
        int i, j;
        i = j = 0;
        while(i<lenS && j<lenT){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else    i++;
        }
        return lenT - j;
        
    }
};