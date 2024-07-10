class Solution {
public:
    int lcs(string str1,string str2,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1==0 || ind2==0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(str1[ind1-1]==str2[ind2-1]){
            return dp[ind1][ind2]=1+lcs(str1,str2,ind1-1,ind2-1,dp);
        }
        return dp[ind1][ind2]=max(lcs(str1,str2,ind1-1,ind2,dp),lcs(str1,str2,ind1,ind2-1,dp));
    }
    int lcs_tab(string str1,string str2,vector<vector<int>>&dp){
        int n=str1.size();
        int m=str2.size();
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=0;i<=m;i++) dp[0][i]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //return lcs(text1,text2,n,m,dp);
        return lcs_tab(text1,text2,dp);
    }
};