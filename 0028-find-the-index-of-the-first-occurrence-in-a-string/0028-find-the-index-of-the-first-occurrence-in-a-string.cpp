class Solution {
public:
vector<int>lps(string need){
    int n=need.size();
    vector<int>ans(n,0);
    int len=0,i=1;
    while(i<n){
        if(need[i]==need[len]){
            len=len+1;
            ans[i]=len;
            i++; 
        }
        else{
            if(len!=0)
            len=ans[len-1];
            else{
                ans[i]=len;
                i++;
            }
        }
    }
    return ans;
}
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int>lps_c=lps(needle);
        int j=0;
        int i=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                j++;
                i++;
            }
            else{
                if(j!=0){
                    j=lps_c[j-1];
                    }
                else {
                    i++;
                }
            }
            if(j==m) return i-j;
        }
        return -1;
    }
};