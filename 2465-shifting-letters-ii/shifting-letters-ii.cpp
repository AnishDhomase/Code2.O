class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> vals(n), relValue(n+1, 0);
        for(int i=0; i<n; i++)
            vals[i] = s[i] - 'a';
        relValue[0] = vals[0];
        for(int i=1; i<n; i++)
            relValue[i] = vals[i] - vals[i-1];
        for(auto shift : shifts){
            int l = shift[0], r = shift[1];
            int add = shift[2] == 0 ? -1 : 1;
            relValue[l] += add;
            relValue[r+1] -= add;
        }
        string ans;
        for(int i=0; i<n; i++){
            relValue[i] += i-1 < 0 ? 0 : relValue[i-1];
            int shiftBy = abs(relValue[i]) % 26;
            shiftBy *= (relValue[i])<0 ? -1 : 1;
            char ch;
            if(shiftBy < 0) ch = 'a' + ((shiftBy + 26) % 26) ;
            else            ch = 'a' + shiftBy;
            ans += ch;
        }
        return ans;
    }
};