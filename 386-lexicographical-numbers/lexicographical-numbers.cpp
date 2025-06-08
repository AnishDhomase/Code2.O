class Solution {
    void generateNext(int i, int n, vector<int> &ans){
        if(i != 0)
            ans.push_back(i);
        for(int dig=0; dig<=9; dig++){
            int nextNum = i*10 + dig;
            if(nextNum <= n && nextNum != 0)
                generateNext(nextNum, n, ans);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        generateNext(0, n, ans);
        return ans;
    }
};