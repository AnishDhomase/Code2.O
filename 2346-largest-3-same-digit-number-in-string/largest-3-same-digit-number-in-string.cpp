class Solution {
public:
    string largestGoodInteger(string num) {
        int dig = -1, n=num.size();
        char dg;
        string ans;

        for(int i=0; i<=n-3; ){
            if(num[i]==num[i+1]){
                if(num[i]==num[i+2]){
                    if(dig == 9)
                        break;
                    else if(dig == -1)
                        dig = num[i] - 48;
                    else if(num[i]-48 > dig){
                        dig = num[i] - 48;
                    }
                    i += 3; 
                }
                else i += 2;
            }
            else
                i++;
        }
        if(dig==-1)
            return ans;
        dg = dig + 48;
        for(int i=0; i<3; i++)
            ans += dg;
        return ans;
        

    }
};