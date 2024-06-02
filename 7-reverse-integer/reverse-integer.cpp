class Solution {
public:
    int reverse(int x) {
        long long rev = 0, n = abs(x);
        while(n>0){
            rev = (rev*10) + n%10;
            n/=10;
        }
        if(x<0){ 
            if(rev > pow(2,31)) return 0;
            return -1 * rev;
        }
        if(rev > pow(2,31)-1) return 0;
        return rev;
    }
}; 