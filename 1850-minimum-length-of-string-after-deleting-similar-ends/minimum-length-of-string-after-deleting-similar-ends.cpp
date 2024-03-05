class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i=0, j=n-1;
        while(i<j){
            if(s[i]==s[j]){
                char ch = s[i];
                while(i<n && s[i]==ch)
                    i++;
                while(0<=j && s[j]==ch)
                    j--;
            }
            else    break;
        }
        if(i<=j)
            return j-i+1;
        return 0;
    }
};