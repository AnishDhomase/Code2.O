class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        bool neg = false;
        if(N<0) neg = true;
        if(neg) N *= -1;
        double ans = 1;
        while(N){
            if(N%2){
                ans *= x;
                N--;
            }
            else{
                x *= x;
                N /= 2;
            }
        }
        if(neg) return 1.0/ans;
        return ans;
    }
};