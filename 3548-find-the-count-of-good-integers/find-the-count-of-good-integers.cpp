typedef long long LL;
class Solution {
    LL fact(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) 
            result *= i;
        
        return result;
    }
    LL permutationOfLengthN(string str){
        int n = str.length();
        vector<int> freq(10, 0);
        for(auto ch: str)   freq[ch-'0'] ++;

        int totalPerms = fact(n);
        for(auto f: freq)   totalPerms /= fact(f);

        if(freq[0] == 0)    return totalPerms;

        freq[0] -= 1;
        int inValidPerm = fact(n-1);
        for(auto f: freq)   inValidPerm /= fact(f);

        return (LL) totalPerms - inValidPerm;
                     
    }
    LL getCnt(int i, string str, int k, unordered_map<string,int> &mp){
        int n = str.length();
        if(i > (n-1)/2){
            LL num = stoll(str);
            if(num % k == 0){
                sort(str.begin(), str.end());
                if(!mp[str]){
                    mp[str] = 1;
                    return permutationOfLengthN(str);
                }    
                else            return 0;
            }
            else                return 0;
        }

        LL cnt = 0;
        for(int ch='0'; ch<='9'; ch++){
            if(i == 0 && ch == '0') continue;
            str[i] = str[n-1-i] = ch;
            cnt += getCnt(i+1, str, k, mp);
        }
        return cnt;
    }
public:
    LL countGoodIntegers(int n, int k) {
        string str;
        for(int i=0; i<n; i++)  str += ' ';
        unordered_map<string,int> mp;
        return getCnt(0, str, k, mp);
    }
};