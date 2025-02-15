class Solution {
    bool isValidPartitionPossible(int sum, int sq, int n){
        if(sq == 0) return sum == n;

        int remSq = sq, subStr;
        for(int i=1; remSq != 0; i++){
            int p = pow(10, i);
            subStr = sq % p;
            remSq  = sq / p;
            if(isValidPartitionPossible(sum + subStr, remSq, n))
                return true;
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int punNum = 0;
        for(int i=1; i<=n; i++){
            if(isValidPartitionPossible(0, i*i, i))
                punNum += i*i;
        }
        return punNum;
    }
};