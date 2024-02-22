class Solution {
    int lenOfNum(int n){
        int l = 0;
        while(n){
            n/=10;
            l++;
        }
        return l;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int lenOfLow = lenOfNum(low), l = lenOfLow; 
        int lenOfHigh = lenOfNum(high); 
        int leftDig = low/pow(10, lenOfLow-1);
        do{
            bool flag = false;
            int seqNum = 0, ld = leftDig;
            for(int i=l-1; i>=0; i--){
                if(ld>9){
                    l++;
                    leftDig = 1;
                    flag = true;
                    break;
                }
                seqNum += ld * pow(10,i);
                ld++;
            }
            if(flag)    continue;
            if(low <= seqNum && seqNum <= high){
                ans.push_back(seqNum);
                leftDig++;
            }
            else if(high < seqNum)
                break;
            else    leftDig++;
        }while(l <= lenOfHigh);
        return ans;
    }
};