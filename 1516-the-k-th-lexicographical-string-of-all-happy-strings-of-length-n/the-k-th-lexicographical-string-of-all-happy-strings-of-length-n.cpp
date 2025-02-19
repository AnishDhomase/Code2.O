class Solution {
    string happyStr(string &str, int &cnt, int n, int k){
        int len = str.length();
        if(len == n){
            cnt ++;
            return cnt == k ? str : "";
        }   

        for(char ch='a'; ch<='c'; ch++){
            if(len == 0 || str[len-1] != ch){
                str += ch;
                string res = happyStr(str, cnt, n, k);
                str.pop_back();
                if(res != "")   return res;
            }
        }
        return "";
    }
public:
    string getHappyString(int n, int k) {
        int cnt = 0;
        string str;
        return happyStr(str, cnt, n, k);
    }
};