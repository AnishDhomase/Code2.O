typedef long long LL;
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        string ans;
        vector<LL> relVal(n+1, 0);
        relVal[0] = s[0] - 'a';
        for(int i=1; i<n; i++)
            relVal[i] = s[i] - s[i-1];
        for(int i=0; i<shifts.size(); i++){
            relVal[0] = (LL) relVal[0] + shifts[i];
            relVal[i+1] = (LL) relVal[i+1] - shifts[i];
        }
        for(int i=0; i<n; i++){
            relVal[i] = (LL) relVal[i] + (i-1 < 0 ? 0 : relVal[i-1]);
            int shiftBy = abs(relVal[i]) % 26;
            int shiftDir = relVal[i] < 0 ? -1 : 1;
            char shiftedChar;
            if(shiftDir < 0)   shiftedChar = ((26-shiftBy) % 26) + 'a';    
            else    shiftedChar = (shiftBy % 26) + 'a';
            ans += shiftedChar;
        }
        return ans;

    }
};