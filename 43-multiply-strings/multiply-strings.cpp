class Solution {
    string add(string num1, string num2){
        string ans;
        int n1 = num1.length(), n2 = num2.length(), i=n1-1, j=n2-1, carry=0;
        while(i>=0 && j>=0){
            string nn1, nn2;
            nn1 += num1[i], nn2 += num2[j];
            int ad = stoi(nn1) + stoi(nn2) + carry;
            carry = ad / 10;
            int dig = ad % 10;
            char digg = dig+48;
            ans = digg + ans;
            i--;
            j--;
        }
        while(i>=0){
            string nn1;
            nn1 += num1[i];
            int ad = stoi(nn1) + carry;
            carry = ad / 10;
            int dig = ad % 10;
            char digg = dig+48;
            ans = digg + ans;
            i--;
        }
        while(j>=0){
            string nn2;
            nn2 += num2[j];
            int ad = stoi(nn2) + carry;
            carry = ad / 10;
            int dig = ad % 10;
            char digg = dig+48;
            ans = digg + ans;
            j--;
        }
        if(carry)
            ans = '1' + ans;
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        string ans = "0";
        int n1 = num1.length(), n2 = num2.length();
        for(int i=n1-1, zero=0; i>=0; i--, zero++){
            int d1 = num1[i] - 48, carry = 0;
            if(d1 == 0)   continue;
            string d1n2;
            for(int j=n2-1; j>=0; j--){
                string nn2;
                nn2 += num2[j];
                int multi = stoi(nn2) * d1 + carry, dig;
                carry = multi / 10;
                dig = multi % 10;
                char digg = dig+48;
                d1n2 = digg + d1n2;
            }
            if(carry != 0){
                char crr = carry+48;
                d1n2 = crr + d1n2;
            }
            for(int z=0; z<zero; z++)
                d1n2 += '0';
            ans = add(ans, d1n2);
        }
        int i=0, ansLen=ans.length();
        while(i < ansLen-1){
            if(ans[i] != '0')   break;
            i++; 
        }
        return ans.substr(i);
    }
};