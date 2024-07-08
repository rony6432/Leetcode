class Solution {
public:
#define mod 1000000007
    long long hash(string s,int radix,int m){
        long long ans=0,factor=1;
        for(int i=m-1;i>=0;i--){
            ans=ans+((s[i]-'a')*factor)%mod;
            factor=(factor*radix)%mod;
        }
        return ans%mod;
    }
    int rab_karp(string source,string b){
        int n=source.size();
        int m=b.size();
        long long power=1,radix=27;
        for(int i=0;i<m;i++) power=(power*radix)%mod;

    //count b hash

        long long target=hash(b,radix,m);
        long long hash_s;
        for(int i=0;i<=n-m;i++){
            if(i==0){
             hash_s=hash(source,radix,m);
            }
            else{
                hash_s=((hash_s*radix)%mod - ((source[i-1]-'a')*power)%mod + (source[i+m-1]-'a')+mod)%mod;
            }
            if(hash_s==target){
                for(int j=0;j<m;j++){
                    if(source[i+j]!=b[j]) break;
                    if(j==m-1) return i;
                }
            }
        }
        return -1;

   }

    int repeatedStringMatch(string a, string b) {
        if(a==b) return 1;
        int cnt=1;
        string source=a;
        while(source.size()<b.size()){
            cnt++;
            source+=a;
        }
        if(source==b) return cnt;
        if(rab_karp(source,b)!=-1) return cnt;
        if(rab_karp(source+a,b)!=-1) return cnt+1;
        return -1;
    }
};