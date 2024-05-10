class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> denominatorInd(n-1,n-1), ans(2);
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> hp; 
        for(int i=0; i<=n-2; i++)
            hp.push({arr[i]/(double)arr[n-1], i});
        while(k){
            k--;
            auto top = hp.top();
            hp.pop();
            int indOfNumerator = top.second, indOfDenominator = denominatorInd[indOfNumerator];
            if(k==0){
                ans[0] = arr[indOfNumerator];
                ans[1] = arr[indOfDenominator];
                break;
            }
            denominatorInd[indOfNumerator] --;
            if(denominatorInd[indOfNumerator] >= 0)
                hp.push({arr[indOfNumerator]/(double)arr[denominatorInd[indOfNumerator]], indOfNumerator});
        }
        return ans;
    }
};