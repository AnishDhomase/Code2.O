class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxCollect = 0;
        unordered_map<int,int> freq;
        int n = fruits.size(), i=0, j=0;
        while(j<n){
            freq[fruits[j]]++;
            if(freq.size() <= 2){
                j++;
            }
            else{
                maxCollect = max(maxCollect, j-i);
                while(freq.size() > 2){
                    freq[fruits[i]]--;
                    if(freq[fruits[i]]==0)
                        freq.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        maxCollect = max(maxCollect, j-i);
        return maxCollect;
    }
};