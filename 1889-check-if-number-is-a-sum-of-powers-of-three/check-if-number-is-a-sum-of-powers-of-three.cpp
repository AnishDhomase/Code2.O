typedef long long LL;
class Solution {
    bool isSumOfPowerOf3(int i, int n){
        if(n == 0)  return true;
        LL minDiduction = pow(3,i);
        if(minDiduction > n)    return false;

        // take
        if(isSumOfPowerOf3(i+1, n-minDiduction))
            return true;
        // don't take
        return isSumOfPowerOf3(i+1, n);
    }

public:
    bool checkPowersOfThree(int n) {
        return isSumOfPowerOf3(0, n);
    }
};