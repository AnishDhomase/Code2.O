class Solution {
    void add1(string &s){
        int len = s.length(), carry='1', i=len-1;
        while(i != -1){
            if(carry == '1'){
                if(s[i] == '1') s[i] = '0';
                else{
                    s[i] = '1';
                    break;
                }
            }
            else    break; 
            i--;
        }
        if(i == -1 && carry == '1')
            s = '1' + s;
    }
    void half(string &s){
        s.pop_back();
    }
public:
    int numSteps(string s) {
        int steps = 0;
        
        while(s.length() != 1){
            steps++;
            if(s[s.length()-1] == '1') add1(s); //odd
            else                       half(s); //even
        }
        return steps;
    }
};