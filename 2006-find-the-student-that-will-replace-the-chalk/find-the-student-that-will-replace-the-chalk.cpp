class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long K = k, n = chalk.size();
        long long chalksReqStudentsInARound = accumulate(chalk.begin(), chalk.end(), 0LL);
        K %= chalksReqStudentsInARound;
        for(int i=0; i<n; i++){
            if(K < chalk[i])
                return i;
            K -= chalk[i];
        }
        return 0;
    }
};