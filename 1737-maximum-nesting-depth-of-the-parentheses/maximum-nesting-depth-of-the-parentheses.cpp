class Solution {
public:
    int maxDepth(string s) {
        int maxDep = 0;
        int ct = 0;
        for(auto ch : s){
            if(ch == '(') ct++;
            else if(ch == ')'){
                maxDep = max(maxDep,ct);
                ct--;
            }
        }
        return maxDep;
    }
};