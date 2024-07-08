class Solution {
public:
#define mod 1000000007
    long long hash(string need,int m,int radix){
        long long ans=0,factor=1;
        for(int i=m-1;i>=0;i--){
            ans=ans+((need[i]-'a')*factor)%mod;
            factor=(factor*radix)%mod;
        }
        return ans%mod;
    }
    int rab_caf(string hay,string need){
        int n=hay.size();
        int m=need.size();
        int radix=27;
        long long power=1;
        for(int i=0;i<m;i++) power=(power*radix)%mod;
        long long need_hash=hash(need,m,radix);
        long long hay_hash;
        for(int i=0;i<=n-m;i++){
            if(i==0){
                hay_hash=hash(hay,m,radix);
            }
            else{
                hay_hash=((hay_hash*radix)%mod-((hay[i-1]-'a')*power)%mod+(hay[i+m-1]-'a')+mod)%mod;
            }
            if(hay_hash==need_hash){
                for(int j=0;j<m;j++){
                    if(need[j]!=hay[i+j]) break;
                    if(j==m-1) return i;
                }
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size()) return -1;
        return rab_caf(haystack,needle);
    }
};