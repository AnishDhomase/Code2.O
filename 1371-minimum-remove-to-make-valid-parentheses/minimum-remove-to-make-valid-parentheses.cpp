class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int n=s.length();
        stack<int> st;
        unordered_set<int> reject;
        for(int i=0; i<n; i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                if(st.size())
                    st.pop();
                else    reject.insert(i);
            }
        }
        while(st.size()){
            reject.insert(st.top());
            st.pop();
        }
        for(int i=0; i<n; i++){
            if(reject.find(i) == reject.end())
                ans += s[i];
            else    reject.erase(i);
        }
        return ans;
        

    }
};