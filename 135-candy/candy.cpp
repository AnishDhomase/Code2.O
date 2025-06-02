class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), totalCandies = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap; //{rating, ind}
        vector<int> hasCandies(n);

        for(int i=0; i<n; i++)
            minHeap.push({ratings[i], i});

        while(minHeap.size() > 0){
            auto lowRatedChild = minHeap.top();
            int i = lowRatedChild.second;
            minHeap.pop();

            int maxAdjCandies = 0;
            if(i-1 >= 0 && ratings[i-1] < ratings[i])
                maxAdjCandies = max(maxAdjCandies, hasCandies[i-1]);
            if(i+1 < n && ratings[i+1] < ratings[i])
                maxAdjCandies = max(maxAdjCandies, hasCandies[i+1]);
            
            hasCandies[i] = 1 + maxAdjCandies;
            totalCandies += hasCandies[i];
        }
        return totalCandies;

    }
};