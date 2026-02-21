class Solution {
    int countSetBits(int n){
        int cnt = 0;
        while(n){
            bool isRightMostBitSet = n & 1;
            if(isRightMostBitSet)   cnt ++;
            n = n >> 1;
        }
        return cnt;
    }
    bool isPrimeNumber(int n) {
        if(n == 1)  return false;
        for(int i=2; i<n; i++){
            bool isDivisible = n % i == 0;
            if(isDivisible) return false;
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i=left; i<=right; i++){
            int setBits = countSetBits(i);
            bool isPrime = isPrimeNumber(setBits);
            if(isPrime) cnt ++;
        }
        return cnt;
    }
};