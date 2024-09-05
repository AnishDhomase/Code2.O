class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = true;
        if((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) 
            sign = false;
        // A/B
        long A = abs(dividend), B = abs(divisor), q = 0;
        while(A >= B){
            int i=0;
            while( A >= (B << (i+1)) )
                i++;
            q += (1 << i);
            A -= (B << i);
        }
        if(q == (1<<31) && sign)    return INT_MAX;
        if(q == (1<<31) && !sign)    return INT_MIN;
        return sign ? q : -q;
    }
};