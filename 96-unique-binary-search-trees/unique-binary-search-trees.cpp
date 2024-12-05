class Solution {
    int getTrees(int l, int r){
        if(l >= r) return 1;

        int ways = 0;
        for(int par=l; par<=r; par++){
            ways += getTrees(l, par-1) * getTrees(par+1, r); 
        }
        return ways;
    }
public:
    int numTrees(int n) {
        return getTrees(1, n);
    }
};