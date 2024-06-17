class Solution {
    int sqrt(int n){
        int l = 0, r = n;
        long long m;
        while(l <= r){
            m = l + (r-l)/2;
            if(m*m == n)
                return m;
            else if(m*m < n)
                l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
public:
    bool judgeSquareSum(int c) {
        for(long long a=0; a*a <= c; a++){
            long long sq = (long long)c - a*a;
            if(sqrt(sq) != -1) 
                return true;
        }
        return false;
    }
};