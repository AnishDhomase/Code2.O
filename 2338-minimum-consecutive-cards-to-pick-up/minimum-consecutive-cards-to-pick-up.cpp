class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size(), minpicks = 1e9; 
        unordered_map<int,int> pos; //{ind+1}
        for(int i=n-1; i>=0; i--){ 
            if(!pos[cards[i]])
                pos[cards[i]] = i+1;
            else{
                minpicks = min(minpicks, pos[cards[i]]-i);
                pos[cards[i]] = i+1;
            }
        }
        if(minpicks==1e9)
            return -1;
        return minpicks;
    }
};