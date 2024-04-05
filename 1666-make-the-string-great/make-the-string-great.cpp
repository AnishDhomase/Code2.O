class Solution {
    bool isGood(char curr, char prev){
        if(curr <= 90){  //uppercase
            if(curr + 32 == prev)
                return false;
        }
        else{   //lowercase
            if(curr - 32 == prev)
                return false;
        }
        return true;
    }
public:
    string makeGood(string s) {
        string goodStr;
        stack<char> st;
        for(auto ch : s){
            if(st.size() && !isGood(st.top(), ch))   
                st.pop();
            else    st.push(ch);
        }
        while(st.size()){
            goodStr = st.top() + goodStr;
            st.pop();
        }
        return goodStr;

    }
};