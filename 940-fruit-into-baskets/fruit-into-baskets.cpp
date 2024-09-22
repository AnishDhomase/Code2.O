class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0, n = fruits.size(), maxL = 0;
        pair<pair<int,int>,int> b1, b2;
        b1 = b2 = {{-1,0},-1}; //{{type,cnt}, lastIndex}
        while(r < n){
            if(b1.first.first == -1){
                b1 = {{fruits[r],1}, r};
            }
            else if(b1.first.first == fruits[r]){
                b1.first.second ++;
                b1.second = r;
            }
            else if(b2.first.first == -1){
                b2 = {{fruits[r],1}, r};
            }
            else if(b2.first.first == fruits[r]){
                b2.first.second ++;
                b2.second = r;
            }
            else{
                maxL = max(maxL, r-l);
                if(b1.second < b2.second){
                    l = b1.second + 1;
                    b1 = {{fruits[r],1}, r};
                }
                else{
                    l = b2.second + 1;
                    b2 = {{fruits[r],1}, r};
                }
            }
            r ++;
        }
        maxL = max(maxL, r-l);
        return maxL;
    }
};