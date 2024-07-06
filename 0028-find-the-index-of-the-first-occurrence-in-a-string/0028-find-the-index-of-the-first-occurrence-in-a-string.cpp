class Solution {
public:
    int strStr(string haystack, string needle) {

        int n1=needle.size();
        int n2=haystack.size();
        if(n2<n1) return -1;
       for(int i=0;i<=n2-n1;i++){
        int j=0;
        while(j<n1 && haystack[i+j]==needle[j]) j++;
        if(j==n1) return i;
       }
       return -1;
    }
};