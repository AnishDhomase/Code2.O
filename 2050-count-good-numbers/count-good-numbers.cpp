typedef long long LL;
class Solution {
    int mod = 1e9 + 7;
    LL getPow(int base, LL power){
        if(power == 0 || base == 1) return 1;

        LL halfOfPower = power/2;
        LL halfResult = getPow(base, halfOfPower);
        LL result = ((LL) halfResult * halfResult) % mod;
        
        if(power % 2 == 0)  return result;
        return result = ((LL) base * result) % mod;
    }

public:
    int countGoodNumbers(long long n) {
        LL evenPlaces = (n+1) / 2;
        LL oddPlaces = n - evenPlaces;
        LL base5ToIndexEvenPlaces = getPow(5, evenPlaces);
        LL base4ToIndexOddPlaces = getPow(4, oddPlaces);
        return ((LL) base5ToIndexEvenPlaces * base4ToIndexOddPlaces) % mod;
    }
};