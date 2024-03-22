class Solution {
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
public:
    long long countVowels(string word) {
        long long ans = 0;
        int n = word.length();
        for(int i=0; i<n; i++){
            if(isVowel(word[i])){
                long long subAns = (long long) (i+1)*(n-i);
                ans += subAns;
            }   
        }
        return ans;
    }
};