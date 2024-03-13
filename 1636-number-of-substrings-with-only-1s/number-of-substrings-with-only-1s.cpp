class Solution {
public:
    int numSub(string s) {
        int i=0, j=0, n=s.length(), mod=1e9+7, ans=0;
        while(i<n && j<n){
            if(s[i]==s[j])  j++;
            else{
                if(s[i]=='1'){
                    long long l = j-i;
                    long long combis = l*(l+1)/2;
                    ans = (ans + combis) % mod;
                }
                i=j;
                j++;
            }
        }
        if(s[i]=='1'){
            long long l = j-i;
            long long combis = l*(l+1)/2;
            ans = (ans + combis) % mod;
        }
        return ans % mod;
    }
};