class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1, true);
        isPrime[0] = isPrime[1] = false;
        int p1 = -1, p2 = -1;
        for(int i=2; i*i<=right; i++){
            if(!isPrime[i])   continue;
            for(int j=i*i; j<=right; j+=i)
                isPrime[j] = false;
        }
        for(int i=left, prevPrime=-1; i<=right; i++){
            if(isPrime[i]){
                if(p1 == -1)    p1 = i;
                else if(p2 == -1)    p2 = i;
                else if((i - prevPrime) < (p2 - p1)){
                    p1 = prevPrime;
                    p2 = i;
                }
                prevPrime = i;
            }
        }
        if(p1 != -1 && p2 != -1)    return {p1, p2};
        return {-1, -1};
    }
};