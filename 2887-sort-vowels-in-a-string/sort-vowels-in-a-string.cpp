class Solution {
public:
    string sortVowels(string s) {
        string ans;
        vector<int> vovelsAscii;
        int n = s.length(), i, j, sz;
        for(auto ch : s){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
                ans+=' ';
                vovelsAscii.push_back(ch);
            }
            else{
                ans+=ch;
            }
        }
        sort(vovelsAscii.begin(), vovelsAscii.end());
        for(i=0,j=0,sz=vovelsAscii.size(); j<sz; i++){
            if(ans[i]==' '){
                ans[i] = vovelsAscii[j];
                j++;
            }
        }
        return ans;

    }
};