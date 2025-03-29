typedef long long LL;
class Solution {
    int mod = 1e9 + 7;
    LL getAPowerB(int a, int b){
        if(a == 1)  return 1;
        if(b == 0)  return 1;

        int half = getAPowerB(a, b/2);
        int res = ((LL)half * half) % mod;
        if(b%2 == 1)    return ((LL)res * a) % mod;
        return res;
    }
    unordered_set<int> sieveOfEratosthenes(int n){
        vector<bool> prime(n + 1, true);

        for (int num = 2; num * num <= n; num++) {
            if (prime[num] == true) {
                for (int i = num * num; i <= n; i += num)
                    prime[i] = false;
            }
        }

        unordered_set<int> primeSet;
        for (int num = 2; num <= n; num++)
            if (prime[num])
                primeSet.insert(num);
        return primeSet;
                
    }

    int getPrimeValueOfNumber(int num, unordered_set<int> &primeSet, unordered_map<int,int> &primeValueMap){
        if(primeValueMap.find(num) != primeValueMap.end())  
            return primeValueMap[num];
        if(primeSet.find(num) != primeSet.end())
            return 1;

        int uniquePrimeFactorsOfNum = 0;
        for(int i=1; i*i<=num; i++){
            if(num % i == 0){
                int anotherFactorOfNum = num / i;
                if(primeSet.find(i) != primeSet.end()) 
                    uniquePrimeFactorsOfNum ++;
                if(anotherFactorOfNum != i && primeSet.find(anotherFactorOfNum) != primeSet.end()) 
                    uniquePrimeFactorsOfNum ++;
            }
        }
        return uniquePrimeFactorsOfNum;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        LL ans = 1;
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        unordered_set<int> primeSet = sieveOfEratosthenes(maxNum);
        unordered_map<int,int> primeValueMap; //N->primeValue(N)
        map<int,LL> mp; //N->T // 'T' times 'N' is having max prime value in all subarrays
        vector<int> rightIndWithGreaterPrimeValue(n), leftIndWithGreaterOrEqualPrimeValue(n);
        primeValueMap[1] = 0;
        for(auto num: nums){
            int val;
            if(primeValueMap.find(num) != primeValueMap.end())  
                val = primeValueMap[num];
            else if(primeSet.find(num) != primeSet.end())
                val = 1;
            else{
                int uniquePrimeFactorsOfNum = 0;
                for(int i=1; i*i<=num; i++){
                    if(num % i == 0){
                        int anotherFactorOfNum = num / i;
                        if(primeSet.find(i) != primeSet.end()) 
                            uniquePrimeFactorsOfNum ++;
                        if(anotherFactorOfNum != i && primeSet.find(anotherFactorOfNum) != primeSet.end()) 
                            uniquePrimeFactorsOfNum ++;
                    }
                }
                val = uniquePrimeFactorsOfNum;
            }
            primeValueMap[num] = val;
            // primeValueMap[num] = getPrimeValueOfNumber(num, primeSet, primeValueMap);
        }
        stack<int> st1, st2;
        for(int i=0; i<n; i++){
            while(!st1.empty() && primeValueMap[nums[st1.top()]] < primeValueMap[nums[i]])
                st1.pop();
            
            if(st1.empty())
                leftIndWithGreaterOrEqualPrimeValue[i] = -1;
            else
                leftIndWithGreaterOrEqualPrimeValue[i] = st1.top();
            st1.push(i);
        }
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && primeValueMap[nums[st2.top()]] <= primeValueMap[nums[i]]){
                st2.pop();
            }
            if(st2.empty())
                rightIndWithGreaterPrimeValue[i] = n;
            else
                rightIndWithGreaterPrimeValue[i] = st2.top();
            st2.push(i);
        }
        for(int i=0; i<n; i++){
            int leftLen = i - leftIndWithGreaterOrEqualPrimeValue[i];
            int rightLen = rightIndWithGreaterPrimeValue[i] - i;
            LL numOfTimesHavingMaxPrimeValueInSubarrays = (LL) leftLen * rightLen;
            mp[nums[i]] += numOfTimesHavingMaxPrimeValueInSubarrays;
        }
        LL K = k;
        for (auto it = mp.rbegin(); it != mp.rend() && K>0; it++) {
            LL num = it->first, freq = it->second;
            if(num == 1)    break;
            LL minBetKandFreq = min<LL>(K, freq);
            ans = ((LL) ans * getAPowerB(num, minBetKandFreq)) % mod;
            K -= minBetKandFreq;      
        }
        return ans;

    }
};