class Solution {
    int getCnt(int i, int num, int n, int lastI){
        if(i >= lastI)  return 1;

        int ways = getCnt(i+1, num, n, lastI);
        int newNum = num + (1<<i);
        if(newNum <= n)
            ways += getCnt(i+2, newNum, n, lastI);
        return ways;
    }
public:
    int findIntegers(int n) {
        int lastSetBit;
        for(int i=31; i>=0; i--)
            if(n & 1<<i){
                lastSetBit = i;
                break;
            }
        return getCnt(0, 0, n, lastSetBit + 1);
    }
};