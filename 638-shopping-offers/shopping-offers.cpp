class Solution {
    int getMinPrize(int i, vector<int> &items, vector<int>& price, vector<vector<int>>& special, map<pair<int,vector<int>>, int> &dp){
        int m = special.size(), n = items.size();
        if(i == m){
            int cost = 0;
            for(int j=0; j<n; j++)
                cost += items[j] * price[j];
            return cost;
        }
        if(dp.find({i,items}) != dp.end())  return dp[{i,items}];
        // ignore offer
        int ignore = getMinPrize(i+1, items, price, special, dp);
        // apply offer
        vector<int> oldItems = items;
        for(int j=0; j<n; j++){
            if(items[j] < special[i][j]){
                items = oldItems;
                return dp[{i,items}] = ignore;
            }
            else items[j] -= special[i][j];
        }
        int apply = special[i][n] + getMinPrize(i, items, price, special, dp);
        items = oldItems;
        return dp[{i,items}] = min(ignore, apply);
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
        int m = special.size(), n = needs.size();
        map<pair<int,vector<int>>, int> dp;
        return getMinPrize(0, needs, price, newSpecial, dp);
    }
};