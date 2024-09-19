class Solution {
    bool isOperator(char op){
        return (op == '+' || op == '-' || op == '*');
    }
    int calc(int a, int b, char op){
        switch(op){
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
        }
        return 1;
    }
    void resOfOperation(char op, vector<int> &lhs, vector<int> &rhs, vector<int> &ans){    
        for(int i=0; i<lhs.size(); i++){
            for(int j=0; j<rhs.size(); j++){
                ans.push_back(calc(lhs[i], rhs[j], op));
            }
        }
    }
    vector<int> compute(string exp){
        bool flag = true;
        vector<int> ans;
        for(int i=0; i<exp.length(); i++){
            if(isOperator(exp[i])){
                flag = false;
                vector<int> lhs = compute(exp.substr(0,i));
                vector<int> rhs = compute(exp.substr(i+1));
                resOfOperation(exp[i], lhs, rhs, ans);
            }
        }  
        if(flag){
            int val = stoi(exp);
            ans.push_back(val);
        }  
        return ans;  
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        return compute(expression);
    }
};