class FoodRatings {
    int sz;
    //{cuisine, set{HighestRating, food}}
    unordered_map<string, set<pair<int,string>>> mp; 
    //{food,{cuisine,rating}}
    unordered_map<string, pair<string,int>> mp1;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        sz = n;
        for(int i=0; i<n; i++){
            mp[cuisines[i]].insert({ratings[i], foods[i]});
            mp1[foods[i]] = {cuisines[i],ratings[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        int initRating = mp1[food].second;
        string cus = mp1[food].first;
        mp1[food].second = newRating;
        mp[cus].erase({initRating, food});
        mp[cus].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        set<string> highRatedFoods;
        int highRating = (*(mp[cuisine].rbegin())).first;
        auto it = mp[cuisine].rbegin();
        while(it != mp[cuisine].rend() && (*it).first == highRating){
            highRatedFoods.insert((*it).second);
            it++;
        }
        return *highRatedFoods.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */