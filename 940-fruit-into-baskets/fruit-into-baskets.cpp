class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0, n = fruits.size(), maxL = 0;
        pair<int,int> b1, b2;
        b1 = b2 = {-1,-1}; //{type,lastIndex}
        while(r < n){
            if(b1.first == -1)
                b1 = {fruits[r], r};
            else if(b1.first == fruits[r])
                b1.second = r; 
            else if(b2.first == -1)
                b2 = {fruits[r], r};            
            else if(b2.first == fruits[r])
                b2.second = r;            
            else{
                maxL = max(maxL, r-l);
                if(b1.second < b2.second){
                    l = b1.second + 1;
                    b1 = {fruits[r], r};
                }
                else{
                    l = b2.second + 1;
                    b2 = {fruits[r], r};
                }
            }
            r ++;
        }
        maxL = max(maxL, r-l);
        return maxL;
    }
};