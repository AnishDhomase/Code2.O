class Solution {
    string invertRev(string s){
        int n = s.length();
        string invRev;
        for(int i=n-1; i>=0; i--){
            char oppo = s[i] == '1' ? '0' : '1';
            invRev += oppo;
        }
        return invRev;
    }
public:
    char findKthBit(int n, int k) {
        string curr = "0";
        for(int i=2; i<=n; i++)
            curr = curr + '1' + invertRev(curr);
        return curr[k-1];
    }
};