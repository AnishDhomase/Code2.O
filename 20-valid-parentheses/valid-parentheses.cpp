class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s){
            if(ch=='(' || ch=='{' || ch=='[')   st.push(ch);
            else{
                if(!st.size())  return false;
                if(ch==')'){
                    if(st.top()!='(')  return false;
                }
                else if(ch==']'){
                    if(st.top()!='[')  return false;
                }
                else{
                    if(st.top()!='{')  return false;
                }
                st.pop();
            }
        }
        return !st.size();
    }
};