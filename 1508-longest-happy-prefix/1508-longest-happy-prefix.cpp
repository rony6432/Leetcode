class Solution {
public:
    int lps(string s){
        int n=s.size();
        vector<int>ans(n,0);
        int len=0,i=1;
        while(i<n){
            if(s[i]==s[len]){
                len+=1;
                ans[i]=len;
                i++;
            }
            else{
                if(len!=0) len=ans[len-1];
                else{
                    ans[i]=len;
                    i++;
                }
            }
        }
       return ans[n-1];
    }
    string longestPrefix(string s) {
        int suff_cnt=lps(s);
        string t="";
        for(int i=0;i<suff_cnt;i++) t+=s[i];
        return t;
    }
};