class Solution {
    int lenOf(int num){
        int l = 0;
        while(num){
            num/=10;
            l++;
        }
        return l;
    }
    int lenOfPrefix(int n1, int n2, unordered_map<int,int> &lenMp, int &max){
        int ans = 0, l1, l2;
        if(lenMp[n1]){
            l1 = lenMp[n1];
        }
        else{
            l1 = lenOf(n1);
            lenMp[n1] = l1;
        }
        if(lenMp[n2]){
            l2 = lenMp[n2];
        }
        else{
            l2 = lenOf(n2);
            lenMp[n2] = l2;
        }
        if(max > min(l1,l2))
            return 0;
        int i=l1, j=l2;      
        while(i && j){
            int dig1 =  n1/pow(10,i-1);
            int dig2 =  n2/pow(10,j-1);
            if(dig1 == dig2)
                ans++;
            else break;
            i--;
            j--;
        }
        if(n1==0 && n2==0)
            return 1;
        return ans;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxPrefix = 0;
        unordered_set<int> s1;
        for(auto num : arr1){
            while(num){
                s1.insert(num);
                num/=10;
            }
        } 
        for(auto num : arr2){
            while(num && maxPrefix < lenOf(num)){
                if(s1.find(num) != s1.end()){
                    maxPrefix = max(maxPrefix, lenOf(num));
                    break;
                }
                num/=10;
            }
        }
        return maxPrefix;

        // unordered_map<int,int> lenMp;
        // int max = 0;
        // for(auto e : arr1){
        //     for(auto f : arr2){
        //         int len = lenOfPrefix(e,f,lenMp,max);
        //         if(max < len)   max = len;
        //     }
        // }
        // return max;
    }
};