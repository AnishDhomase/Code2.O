class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i=0, j=31;
        while(i<=j){
            int mid = (i+j)/2;
            long pow2_mid = (long) pow(2, mid);
            if(pow2_mid == n) return true;
            else if(pow2_mid < n)  i = mid+1;
            else                j = mid-1;
        }
        return false;
    }
};