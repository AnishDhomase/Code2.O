class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        bool flag = false;
        for(int i=0; i<32; i++){
            if(left > pow(2,i)-1)
                continue;
            if(left <= pow(2,i)-1 && right <= pow(2,i)-1){
                flag = true;  
            }
            break;
        }
        if(flag==false)
            return 0;
        if(left == right)   return left;
        long long ans = left;
        for(long long i=left+1; i<=right; i++){
            ans = ans & i;
        }
        return ans;
    }
};