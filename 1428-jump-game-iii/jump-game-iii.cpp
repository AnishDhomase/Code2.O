class Solution {
    bool getCanReach(int i, vector<int>& arr, vector<int> &vis){
        int n = arr.size();
        if(arr[i] == 0) return true;
        if(vis[i] == 1)  return false;
        vis[i] = 1;

        if(i - arr[i] >= 0)
            if(getCanReach(i - arr[i], arr, vis))
                return true;
        if(i + arr[i] < n)
            return getCanReach(i + arr[i], arr, vis);
        return false;        
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        return getCanReach(start, arr, vis);
    }
};