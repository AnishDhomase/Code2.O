class Solution {
    int dfs(int target, vector<int> &minPaths){
        if(target==0)   return 0;
        if(minPaths[target] != -1)
            return minPaths[target];
        int minPth = 1e9, pth;
        for(int i=1; i*i<=target; i++){
            pth = 1 + dfs(target-i*i, minPaths);
            minPth = minPth < pth ? minPth : pth;
        }
        return minPaths[target] = minPth;
    }
public:
    int numSquares(int n) {
        vector<int> minPaths(n+1,-1);
        return dfs(n, minPaths);
    }
};