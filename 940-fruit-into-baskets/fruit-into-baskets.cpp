class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0, n = fruits.size(), maxL = 0;
        pair<int,int> b1, b2;
        b1 = b2 = {-1,0}; //{type,cnt}
        while(r < n){
            if(b1.first == -1){
                b1 = {fruits[r],1};
            }
            else if(b1.first == fruits[r])
                b1.second ++;
            else if(b2.first == -1){
                b2 = {fruits[r],1};
            }
            else if(b2.first == fruits[r])
                b2.second ++;
            else{
                maxL = max(maxL, r-l);
                while(b1.second !=0 && b2.second != 0){
                    if(fruits[l] == b1.first)   b1.second --;
                    else                        b2.second --;
                    l ++;
                }
                if(b1.second == 0){
                    b1.first = fruits[r]; 
                    b1.second = 1; 
                }
                if(b2.second == 0){
                    b2.first = fruits[r]; 
                    b2.second = 1; 
                }
            }
            r ++;
        }
        maxL = max(maxL, r-l);
        return maxL;
    }
};