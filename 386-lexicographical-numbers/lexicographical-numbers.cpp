class Solution {
    void getPerm(int start, int n, vector<int> &ans){
        if(start <= n){
            if(start !=0) ans.push_back(start);
        }
        
        for(int i=0; i<10; i++){
            if(start==0 && i==0)    continue;
            int nextPerm = start * 10 + i;
            if(nextPerm <= n)
                getPerm(nextPerm, n, ans);
            else return;
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        getPerm(0, n, ans);
        return ans;
    }
};