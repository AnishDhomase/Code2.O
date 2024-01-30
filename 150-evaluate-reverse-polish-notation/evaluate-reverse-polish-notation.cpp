class Solution {
    bool isoperator(string t){
        if(t =="+"|| t=="-" || t=="*" || t=="/")
            return true;
        return false;
    }
    string calc(string l, string r, string op){
        int lop = stoi(l), rop = stoi(r), ans;
        if(op == "+")   ans = lop + rop;
        if(op == "-")   ans = lop - rop;
        if(op == "*")   ans = lop * rop;
        if(op == "/")   ans = lop / rop;
        return to_string(ans);
    }
public:
    int evalRPN(vector<string>& tokens) {
        string lop, rop;
        stack<string> S;
        for(auto token : tokens){
            if(!isoperator(token)){
                S.push(token);
            }
            else{
                rop = S.top();
                S.pop();
                lop = S.top();
                S.pop();
                string calculatedValue = calc(lop, rop, token);
                S.push(calculatedValue);
            }
        }
        string ans = S.top();
        return stoi(ans);
    }
};