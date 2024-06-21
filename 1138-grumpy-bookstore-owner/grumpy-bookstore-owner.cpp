class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int secretStart = 0, maxSatisfied = 0, satisfied = 0;
        for(int i=0; i<n; i++){
            if(i<minutes || !grumpy[i])
                satisfied += customers[i];
        }
        maxSatisfied = satisfied;
        while(secretStart < (n - minutes)){
            if(grumpy[secretStart]){
                satisfied -= customers[secretStart];
            }
            if(grumpy[secretStart + minutes]){
                satisfied += customers[secretStart + minutes];
            }
            maxSatisfied = max(maxSatisfied, satisfied);
            secretStart++;
        }
        return maxSatisfied;
    }
};