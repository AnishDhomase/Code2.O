class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        string ans;
        if(numRows == 1)    return s;
        for(int i=0,g1=(numRows-1)*2,g2=0;  i<numRows;  i++,g1-=2,g2+=2){
            if(i==0){
                for(int j=i; j<n; ){
                    ans += s[j];
                    j += g1;
                }
            }
            else if(i==numRows-1){
                for(int j=i; j<n; ){
                    ans += s[j];
                    j += g2;
                }
            }
            else{
                bool flagG1 = true;
                for(int j=i; j<n; ){
                    ans += s[j];
                    if(flagG1){
                        j += g1;
                        flagG1 = false;
                    }
                    else{
                        j += g2;
                        flagG1 = true;
                    }
                }
            }
        }
        return ans;
    }
};