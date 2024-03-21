class Solution {
public:
    int numberOfSubstrings(string s) {
        // int ans = 0, n = s.length();
        // for(int i=0; i<=n-3; i++){
        //     int a, b, c;
        //     a = b = c = 0;
        //     for(int j=i; j<n; j++){
        //         if(s[j]=='a')   a++;
        //         else if(s[j]=='b')   b++;
        //         else   c++;
        //         if(a && b && c){
        //             ans += n-j;
        //             break;
        //         }
        //     }
        //     if(!(a && b && c))
        //         break;
        // }
        // return ans;

        int ans = 0, n = s.length();
        int a, b, c, i, j;
        a = b = c = 0;
        for(i=0, j=0; i<=n-3; i++){
            for(; j<=n; j++){
                if(a && b && c){
                    ans += n-(j-1);
                    if(s[i]=='a')   a--;
                    else if(s[i]=='b')   b--;
                    else   c--;
                    break;
                }
                if(j==n)    break;
                if(s[j]=='a')   a++;
                else if(s[j]=='b')   b++;
                else   c++;
            }
        }
        return ans;
    }
};