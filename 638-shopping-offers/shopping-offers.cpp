class Solution {
    int getMinPrize(int i, vector<int> &items, vector<int>& price, vector<vector<int>>& special){
        int m = special.size(), n = items.size();
        if(i == m){
            int cost = 0;
            for(int j=0; j<n; j++)
                cost += items[j] * price[j];
            return cost;
        }
        // ignore offer
        int ignore = getMinPrize(i+1, items, price, special);
        // apply offer
        vector<int> oldItems = items;
        for(int j=0; j<n; j++){
            if(items[j] < special[i][j]){
                items = oldItems;
                return ignore;
            }
            else items[j] -= special[i][j];
        }
        int apply = special[i][n] + getMinPrize(i, items, price, special);
        items = oldItems;
        return min(ignore, apply);
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>, int> mp;
        for(auto s : special){
            int price = s.back();
            s.pop_back();
            if(mp.find(s) == mp.end())
                mp[s] = price;
            else if(price < mp[s])
                mp[s] = price;
        }
        vector<vector<int>> newSpecial;
        for(auto it : mp){
            auto vec = it.first;
            vec.push_back(it.second);
            newSpecial.push_back(vec);
        }   
        return getMinPrize(0, needs, price, newSpecial);
    }
};