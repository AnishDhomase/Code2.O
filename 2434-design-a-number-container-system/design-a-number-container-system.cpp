class NumberContainers {
    map<int,int> mp;
    map<int,set<int>> freq;
public:
    NumberContainers() {
        
    }
    void change(int index, int number) {
        if(mp.find(index) != mp.end()){
            int prevNum = mp[index];
            freq[prevNum].erase(index);     
        }
        mp[index] = number;
        freq[number].insert(index);
    }
    
    int find(int number) {
        if(freq[number].size() == 0)    return -1;
        return *freq[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */