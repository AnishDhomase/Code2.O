class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size(), i=0;
        vector<int> ans(n,-1);
        sort(deck.begin(), deck.end());
        queue<int> q;
        for(int i=0; i<n; i++)
            q.push(i);
        while(i<n){
            ans[q.front()] = deck[i];
            q.pop();
            if(q.size()){
                q.push(q.front());
                q.pop();
            }
            i++;
        }
        return ans;
        
        
    }
};