class Solution {
    int getReqStores(int maxProd, vector<int> quantities){
        int storesReq = 0;
        for(auto q : quantities){
            storesReq += q/maxProd;
            if(q%maxProd)   
                storesReq++;
        }
        return storesReq;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        int ans;
        while(low <= high){
            int mid = low + (high-low)/2;
            int stores = getReqStores(mid, quantities);
            if(stores <= n){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        int maxProd = 0;
        for(auto q : quantities){
            if(q/ans)   return ans;
            maxProd = max(maxProd, q%ans);
        }
        return maxProd;
    }
};