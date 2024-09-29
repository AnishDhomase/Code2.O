class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = 0, setbitsNum2 = 0;
        for(int i=0; i<=31; i++){
            if(num2 & 1<<i)
                setbitsNum2 ++;
        }
        for(int i=31; i>=0; i--){
            int bit = (num1 & 1<<i) ? 1 : 0;
            if(setbitsNum2 > 0 && bit == 1){
                setbitsNum2 --;
                x += 1<<i;
            }
        }
        int i=0;
        while(setbitsNum2 > 0){
            if(x & 1<<i){
                i ++;
                continue;
            }
            setbitsNum2 --;
            x += 1<<i;
        }
        return x;
    }
};