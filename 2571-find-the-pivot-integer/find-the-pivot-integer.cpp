class Solution {
public:
    int pivotInteger(int n) {
        int x = pow(n*(n+1)/2, 0.5);
        if(x*x == n*(n+1)/2)    return x;
        return -1;
    }
};