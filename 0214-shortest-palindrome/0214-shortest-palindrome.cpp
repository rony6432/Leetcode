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
                if(len!=0)len=ans[len-1];
                else {
                    ans[i]=len;
                    i++;
                }
            }
        }
        return ans[n-1];
    }
    string shortestPalindrome(string s) {
        if(s=="") return "";

        string t=s;
        reverse(s.begin(),s.end());
        t+='$';
        t+=s;
        reverse(s.begin(),s.end());
        int match=lps(t);
        string append_str=s.substr(match);
        reverse(append_str.begin(),append_str.end());
        return append_str+s;
    }
};