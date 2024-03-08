class Solution {
    bool isPrice(string s){
        if(s[0] != '$') return false;
        int n = s.length();
        if(n==1)    return false;
        for(int i=1; i<n; i++){
            if(s[i]<48 || 57<s[i])
                return false;
        }
        return true;
    }
    string addDisc(string p, double disc){
        long long num = stoll(p.substr(1));
        long double discAmt = num * disc;
        long double discNum = num - discAmt;
        string discPrice;
        discPrice += '$' + to_string(discNum);
        int i;
        for(i=0; i<discPrice.length(); i++){
            if(discPrice[i] == '.')
                break;   
        }
        return discPrice.substr(0, i+3);
    }
public:
    string discountPrices(string sentence, int discount) {
        double disc = discount * 0.01;
        string ans;
        int n = sentence.length(), i, j;
        for(i=0, j=0; i<=n; i++){
            if(i==n || sentence[i] == ' '){
                string sub = sentence.substr(j, i-j);
                if(isPrice(sub)){
                    sub = addDisc(sub,disc);
                }
                ans += sub;
                if(i != n)
                    ans += ' ';
                j = i+1;
            }
        }
        return ans;
    }
};